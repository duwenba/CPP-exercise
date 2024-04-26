//
// Created by 22753 on 2024/4/26.
//

#include "Readers.h"
#include <iostream>

#include <fstream>
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
        printHex<typeof(m_head.indexToLocFormat)>(m_head.indexToLocFormat,"indexToLocFormat");
        return m_head;
    }
} // reader
// truetype