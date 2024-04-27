//
// Created by 22753 on 2024/4/26.
//

#ifndef TABLES_READERS_H
#define TABLES_READERS_H

#include <Tables/Tables.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <bitset>
#include <memory>
#include <string>
#include <type_traits>
#include <cstdint>

using std::shared_ptr;

using namespace font::table;

namespace font::reader {


    template<typename T,
            typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, bool>::value, bool>::type = true>
    void toBigEndian(T & value) {
        if constexpr (sizeof(T) == 1) {
            // uint8_t本身就是1字节，无需转换字节序
            return;
        } else {
            // 对于2字节和4字节类型，我们需要交换高低字节
            auto bytes = reinterpret_cast<uint8_t*>(&value);
            if constexpr (sizeof(T) == 2) { // uint16_t
                std::swap(bytes[0], bytes[1]);
            } else if constexpr (sizeof(T) == 4) { // uint32_t
                std::swap(bytes[0], bytes[3]);
                std::swap(bytes[1], bytes[2]);
            }
        }
    }

    template<typename T>
    void read(std::ifstream &file, T &number) {
        file.read(reinterpret_cast<char *>(&number), sizeof(number));
        toBigEndian(number);
    }

    template<typename T>
    /// retrun the context
    T read(std::ifstream &file) {
        T number = 0;
        file.read(reinterpret_cast<char *>(&number), sizeof(number));
        toBigEndian(number);
        return number;
    }

    template<typename T>
    void printHex(T number, const string &name) {
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(sizeof(T)*2) << std::hex << number;
        std::cout << name << ":\t0x" << ss.str() << std::endl;
    }

    bool checkBit(uint8_t flag,uint8_t index);

    FontDirection readeFontDirection(ifstream & file);
    TableDirection readTableDirection(ifstream & file);

    head readhead(ifstream & file);

    loca readloca(ifstream & file,uint16_t numGlyphs);

    uint16_t readnumGlyphs(ifstream & file);

    GlyphsDes readGlyphsDes(ifstream & file);
    GlyphsData readGlyphsData(ifstream & file,int16_t numberOfContours);

    vector<int16_t> readPoints(ifstream & file,const vector<uint8_t> & flags,bool isX);


}


#endif //TABLES_READERS_H
