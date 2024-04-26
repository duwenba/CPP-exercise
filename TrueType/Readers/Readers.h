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
    FontDirection readeFontDirection(ifstream & file);

    template<typename T,
            typename std::enable_if<std::is_unsigned<T>::value && (sizeof(T) >= 1 && sizeof(T) <= 4), bool>::type = true>
    void toBigEndian(T &value) {
        if constexpr (sizeof(T) == 1) {
            // uint8_t本身就是1字节，无需转换字节序
            return;
        } else {
            // 对于2字节和4字节类型，我们需要交换高低字节
            auto bytes = reinterpret_cast<uint8_t *>(&value);
            if constexpr (sizeof(T) == 2) { // uint16_t
                std::swap(bytes[0], bytes[1]);
            } else if constexpr (sizeof(T) == 4) { // uint32_t
                std::swap(bytes[0], bytes[3]);
                std::swap(bytes[1], bytes[2]);
            }
        }
    }

    template<typename T>
    T read(std::ifstream &file, T &number) {
        file.read(reinterpret_cast<char *>(&number), sizeof(number));
        toBigEndian(number);
//        std::cout << "number " <<std::bitset<32>( number).to_string()<< std::endl;
        return number;
    }

    template<typename T>
    void printHex(T number, const string &name) {
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(sizeof(T)*2) << std::hex << number;
        std::cout << name << ":\t0x" << ss.str() << std::endl;
    }


    TableDirection readTableDirection(ifstream & file);

    head readhead(ifstream & file);


}


#endif //TABLES_READERS_H
