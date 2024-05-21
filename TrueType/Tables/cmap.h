//
// Created by 22753 on 2024/4/30.
//

#ifndef TABLES_CMAP_H
#define TABLES_CMAP_H
#include <vector>
#include <fstream>
#include <cstdint>
#include <unordered_map>
#include <tuple>


using namespace std;

namespace font::table {
    using EncodingRecord = struct {
        uint16_t platformID;
        uint16_t encodingID;
        uint32_t offset;
    };
    using Map_f4 = struct {
        uint16_t format{0}; // 格式
        uint16_t length{0}; // 长度
//        uint16_t language{0}; // 语言
        uint16_t segCountX2{0}; // 段数
//        uint16_t searchRange{0}; // 搜索范围
//        uint16_t entrySelector{0}; // 入口选择器
//        uint16_t rangeShift{0}; // 范围偏移
        vector<uint16_t> endCode; // 结束码
        vector<uint16_t> startCode; // 开始码
        vector<uint16_t> idDelta; // 偏移量
        vector<uint16_t> idRangeOffset; // 范围偏移
        vector<uint16_t> glyphIdArray; // 字形ID数组
    };
    class cmap {
    private:
        uint16_t version{0};
        uint16_t numTables{0};
        vector<EncodingRecord> encodingRecords; // 编码记录表
        Map_f4 map_f4; // 格式4 cmap
        uint16_t defaultPlatformID{0};
        uint16_t defaultEncodingID{3};
    public:
        uint16_t getDefaultEncodingId() const;

        void setDefaultEncodingId(uint16_t defaultEncodingId);

        uint16_t getDefaultPlatformId() const;

        void setDefaultPlatformId(uint16_t defaultPlatformId);

    private:
        void readMap_f4(ifstream &file, uint32_t offset);

    public:
        cmap() = default;
        cmap(ifstream &file, uint32_t offset);

        auto operator[](uint16_t platformID, uint16_t encodingID) const -> uint32_t;

        auto findGlyphIndexInFormat4(const uint16_t targetCharCode)  -> uint16_t;
    };
}

#endif //TABLES_CMAP_H
