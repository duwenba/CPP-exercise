//
// Created by 22753 on 2024/4/26.
//

#include "TrueType.h"
#include <Readers/Readers.h>

#include <memory>
using namespace font::reader;

string readtag(uint32_t  input ){
    char* chars = new char[5];
    chars[0] = static_cast<uint8_t>(input >> 24);
    chars[1] = static_cast<uint8_t>((input >> 16) & 0xFF);
    chars[2] = static_cast<uint8_t>((input >> 8) & 0xFF);
    chars[3] = static_cast<uint8_t>(input & 0xFF);
    chars[4] = '\0'; // end of string
    return string(chars);
}

TrueType::TrueType(const string &file_path) {
    font_file = ifstream(file_path, ios::binary);
    if (!font_file.is_open()) {
        throw runtime_error("Failed to open font file: " + file_path);
    }
    font_direction = readeFontDirection(font_file);
//    cout << " i " << " tag \t" << "offset    " << "length  " << endl;
//    cout << "-----------------------------------" << endl;
    for (int i = 0; i < font_direction.numTables; i++) {
        auto table = std::make_shared<TableDirection>(readTableDirection(font_file));
        table_direction[readtag(table->tag)] = table;
//        cout << std::setw(2) << i << "  "<< readtag(table->tag)<<"\t";
//        cout << std::setw(7) << table->offset<<"\t" ;
//        cout << std::setw(7) << table->length << endl;
    }
}

head TrueType::gethead() {
    font_file.seekg(table_direction["head\0"]->offset);
    auto m_head = readhead(font_file);
    return m_head;
}

