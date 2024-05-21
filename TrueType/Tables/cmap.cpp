//
// Created by 22753 on 2024/4/30.
//
#include <cstdint>
#include <iostream>
#include <fstream>
#include "cmap.h"
#include "Readers/Readers.h"
using namespace font::reader;

using namespace std;


namespace font::table {

    cmap::cmap(ifstream &file, uint32_t offset) {
        file.seekg(offset);
        version = read<uint16_t>(file);
        numTables = read<uint16_t>(file);
        encodingRecords.reserve(numTables);

        for (int i = 0; i < numTables; i++) {
            auto platformID = read<uint16_t>(file); // Platform ID
            auto encodingID = read<uint16_t>(file); // Encoding ID
            auto m_offset = read<uint32_t>(file); // Offset
            encodingRecords.push_back(EncodingRecord{platformID, encodingID, m_offset});
        }

        // Find the default encoding
        readMap_f4(file, offset + (*this)[defaultPlatformID, defaultEncodingID]);

    }

    auto cmap::operator[](uint16_t platformID, uint16_t encodingID) const -> uint32_t {
        for (auto record : encodingRecords) {
            if (record.platformID == platformID && record.encodingID == encodingID) {
                return record.offset;
            }
        }
        return 0;
    }

    auto cmap::getDefaultEncodingId() const -> uint16_t {
        return defaultEncodingID;
    }

    void cmap::setDefaultEncodingId(uint16_t defaultEncodingId) {
        defaultEncodingID = defaultEncodingId;
    }

    auto cmap::getDefaultPlatformId() const -> uint16_t {
        return defaultPlatformID;
    }

    void cmap::setDefaultPlatformId(uint16_t defaultPlatformId) {
        defaultPlatformID = defaultPlatformId;
    }

    void cmap::readMap_f4(ifstream &file, uint32_t offset) {

        file.seekg(offset);
        auto format = read<uint16_t>(file);
        if(format!= 4) {
            throw std::runtime_error("cmap format not supported");
        }

        map_f4.format = format;
        map_f4.length = read<uint16_t>(file);
        file.ignore(2); // 跳过language
        map_f4.segCountX2 = read<uint16_t>(file);
        file.ignore(6); // 跳过searchRange, entrySelector, rangeShift
//        map_f4.searchRange = read<uint16_t>(file);
//        map_f4.entrySelector = read<uint16_t>(file);
//        map_f4.rangeShift = read<uint16_t>(file);
        // 读取endCode, startCode, idDelta, idRangeOffset
        map_f4.endCode.reserve(map_f4.segCountX2 / 2);
        map_f4.startCode.reserve(map_f4.segCountX2 / 2);
        map_f4.idDelta.reserve(map_f4.segCountX2 / 2);
        map_f4.idRangeOffset.reserve(map_f4.segCountX2 / 2);

        for (int i = 0; i < map_f4.segCountX2 / 2; i++) {
            map_f4.endCode.push_back(read<uint16_t>(file));
        }
        file.ignore(2); // 跳过reservedPad
        for (int i = 0; i < map_f4.segCountX2 / 2; i++) {
            map_f4.startCode.push_back(read<uint16_t>(file));
        }
        for (int i = 0; i < map_f4.segCountX2 / 2; i++) {
            map_f4.idDelta.push_back(read<int16_t>(file));
        }
        for (int i = 0; i < map_f4.segCountX2 / 2; i++) {
            map_f4.idRangeOffset.push_back(read<uint16_t>(file));
        }


        // 读取glyphIdArray
        size_t glyphIdArrayLength = 0;
        // 计算总长度
        for (int i = 0; i < map_f4.segCountX2 / 2; i++)  {
            if (map_f4.idRangeOffset[i] != 0) {
                // 计算该段内字符的数量
                size_t charCountInSegment = map_f4.endCode[i] - map_f4.startCode[i] + 1;
                // 每个字形索引占用2字节
                size_t segmentLength = charCountInSegment * 2;
                // 更新总长度，考虑到idRangeOffsets给出的是相对于偏移数组自身的偏移
                // 我们只关心段长度来累加，而不是直接使用idRangeOffsets的值
                glyphIdArrayLength += segmentLength;
            }
        }
        map_f4.glyphIdArray.reserve(glyphIdArrayLength);
        for (int i = 0; i < glyphIdArrayLength; i++) {
            map_f4.glyphIdArray.push_back(read<uint16_t>(file));
        }

    }

    auto cmap::findGlyphIndexInFormat4(const uint16_t targetCharCode) -> uint16_t {
        // 找到targetCharCode所在的段
        int segIndex = 0;
        while (segIndex < map_f4.segCountX2 / 2 && map_f4.endCode[segIndex] < targetCharCode) {
            segIndex++;
        }
        if (map_f4.endCode[segIndex] == 0xFFFF || segIndex == 0) return 0;
        auto startCode = map_f4.startCode[segIndex];
        auto idDelta = map_f4.idDelta[segIndex];
        auto idRangeOffset = map_f4.idRangeOffset[segIndex];
        auto charCode = targetCharCode - startCode;
        // 处理idRangeOffset
        if (idRangeOffset == 0) {
            // 直接映射
            return (charCode + idDelta);
        }

        //间接映射
        //计算方法：
        // 1. 计算charCode在段内的偏移位置，即charCode - startCode
         // 2. 计算charCode在段内的相对偏移位置，即charCode - startCode + idRangeOffset
         // 3. 读取idRangeOffset位置的字形索引，并加上相对偏移位置，得到最终的字形索引
        size_t charIndexInSegment = charCode - startCode;
        size_t relativeOffset = charCode - startCode + idRangeOffset;
        size_t absoluteOffset = relativeOffset * 2;
        uint16_t glyphIndex = map_f4.glyphIdArray[absoluteOffset];
        return (glyphIndex + idDelta);

    }
}