//
// Created by 22753 on 2024/4/26.
//

#ifndef TRUETYPE_FONTDIRECTION_H
#define TRUETYPE_FONTDIRECTION_H


#include <cstdint>
#include <fstream>


/**
| Type   | Name             | Description                                            |
| ------ | -----------      | ------------------------------------------------------ |
| uint32 | scalerType       | 表示文件类型.0x74727565(true)或者0x00010000都是ttf格式     |
| uint16 | numTables        | 表数量                                                  |
| uint16 | searchRange      | (maximum power of 2 <= numTables)*16                   |
| uint16 | entrySelector    | log2(maximum power of 2 <= numTables)                  |
| uint16 | rangeShift       | numTables*16-searchRange                               |
 */
class FontDirection {
public:
    FontDirection(std::basic_ifstream<char> ifstream);

    Uint32 scalerType;
    Int16 numTables;
    Int16 searchRange;
    Int16 entrySelector;
    Int16 rangeShift;
};


#endif //TRUETYPE_FONTDIRECTION_H
