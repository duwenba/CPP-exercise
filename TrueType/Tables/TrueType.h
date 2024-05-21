//
// Created by 22753 on 2024/4/26.
//

#ifndef TRUETYPE_TRUETYPE_H
#define TRUETYPE_TRUETYPE_H

#include "Tables.h"

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <memory>

using std::shared_ptr;


class TrueType {
private:
    //字体文件路径
    std::string font_path;
    //字体文件指针
    std::ifstream font_file;
    //FontDirection
    font::table::FontDirection font_direction;

public:
    //numGlyphs
    uint16_t numGlyphs;
    std::unordered_map<
            string ,
            shared_ptr<font::table::TableDirection> > table_direction;

    TrueType() = default;
    explicit TrueType(const string & file_path);

    ~TrueType() {
        font_file.close();
    }

    auto gethead() -> font::table::head;

    auto getloca() -> font::table::loca;

    auto getGlyphs(uint16_t index) -> font::table::Glyphs;

    auto getcmap() -> font::table::cmap;

};


#endif //TRUETYPE_TRUETYPE_H
