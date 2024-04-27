//
// Created by 22753 on 2024/4/26.
//

#include "Readers.h"
#include <iostream>

#include <fstream>
#include <array>
#include <cstdint>
#include <string>

namespace font::reader {
    FontDirection readeFontDirection(ifstream & file){
        auto font_direction = FontDirection();
        read<uint32_t>(file, font_direction.scalerType);
        read<uint16_t>(file,font_direction.numTables);
        read<uint16_t>(file,font_direction.searchRange);
        read<uint16_t>(file,font_direction.entrySelector);
        read<uint16_t>(file,font_direction.rangeShift);
        return font_direction;
    }

    TableDirection readTableDirection(ifstream &file) {
        auto table_direction =  TableDirection();
        read<uint32_t>(file, table_direction.tag);
        file.ignore(4);
        read<uint32_t>(file, table_direction.offset);
        read<uint32_t>(file, table_direction.length);
        return table_direction;
    }

    head readhead(ifstream &file) {
        auto m_head = head();
        file.ignore( 50);
        read<uint16_t>(file, m_head.indexToLocFormat);
        //printHex<typeof(m_head.indexToLocFormat)>(m_head.indexToLocFormat,"indexToLocFormat");
        return m_head;
    }

    loca readloca(ifstream &file,uint16_t numGlyphs) {
        auto m_loca = loca(numGlyphs);
        for (int i = 0; i < numGlyphs; i++)
            m_loca.getOffsets()->push_back(read<uint32_t>(file));
        return m_loca;
    }

    uint16_t readnumGlyphs(ifstream &file) {
        file.ignore(4);
        return read<uint16_t>(file);
    }

    GlyphsDes readGlyphsDes(ifstream &file) {
        auto m_GlyphsDes = GlyphsDes();
        read<int16_t>(file, m_GlyphsDes.numberOfContours);
        read<int16_t>(file, m_GlyphsDes.xMin);
        read<int16_t>(file, m_GlyphsDes.yMin);
        read<int16_t>(file, m_GlyphsDes.xMax);
        read<int16_t>(file, m_GlyphsDes.yMax);
        return m_GlyphsDes;
    }

    GlyphsData readGlyphsData(ifstream &file, int16_t numberOfContours) {
        auto m_GlyphsData = GlyphsData();
        if (numberOfContours < 0) {
            throw std::runtime_error("Composite glyphs not supported yet");
        }
        // read endPtsOfContours
        m_GlyphsData.endPtsOfContours.reserve(numberOfContours);
        for (int i = 0; i < numberOfContours; ++i) {
            m_GlyphsData.endPtsOfContours.push_back(read<uint16_t>(file));
        }
        // skip instruction
        m_GlyphsData.instructionLength = read<uint16_t>(file);
        m_GlyphsData.instructions.reserve(m_GlyphsData.instructionLength);
        for (int i = 0; i < m_GlyphsData.instructionLength; ++i) {
            m_GlyphsData.instructions.push_back(read<uint8_t>(file));
        }
        // read flags
        m_GlyphsData.flags.reserve(m_GlyphsData.endPtsOfContours.back() + 1);
        for (int i = 0; i < m_GlyphsData.endPtsOfContours.back() + 1;) {
            auto flag = read<uint8_t>(file);
            m_GlyphsData.flags.push_back(flag);
            ++i;
            if (checkBit(flag, 3)) {
                for (int j = 0; j < read<uint8_t>(file) ; ++j) {
                    m_GlyphsData.flags.push_back(flag);
                    ++i;
                }
            }
        }
        //  read xCoordinates
        m_GlyphsData.xCoords = readPoints(file, m_GlyphsData.flags, true);
        //  read yCoordinates
        m_GlyphsData.yCoords = readPoints(file, m_GlyphsData.flags, false);

        // print points
        /*
         for (int i = 0; i < m_GlyphsData.endPtsOfContours.back() + 1; ++i) {
                cout<< setw(2) << i << ": "
                    //<< std::bitset<8>(m_GlyphsData.flags[i]).to_string()
                    << " ("
                    << setw(4) << m_GlyphsData.xCoords[i] << ","
                    << setw(4) << m_GlyphsData.yCoords[i] <<")" << endl;
            }
        */
        return m_GlyphsData;
    }

    bool checkBit(uint8_t flag, uint8_t index) {
        return ((flag >> index)  & 1) == 1 ;
    }

    vector<int16_t> readPoints(ifstream &file, const vector<uint8_t> &flags, bool isX) {
        auto count = flags.size();
        auto points = vector<int16_t>();
        points.reserve(count);
        auto lengthBit = isX ? 1 : 2;
        auto signBit = isX ? 4 : 5;
        for (int i = 0; i < count; ++i) {
            auto n = points.empty() ? 0 : points[points.size() - 1];
            if (checkBit(flags[i], lengthBit)) {
                // read 1 byte
                auto value = read<uint8_t>(file);
                if (!checkBit(flags[i], signBit)) {
                    // negative number
                    points.push_back(n - value);
                }else {
                    // positive number
                    points.push_back(n + value);
                }
            } else {
                // longer than 1 byte
                if (checkBit(flags[i], signBit)) {
                    // repeat last value
                    if (points.empty()) points.push_back(0);
                    else points.push_back(points[i - 1]);
                } else {
                    // read 2 bytes
                    auto value = read<int16_t>(file);
                    points.push_back(n + value);
                }
            }
        }
        return points;
    }


} // reader
// truetype