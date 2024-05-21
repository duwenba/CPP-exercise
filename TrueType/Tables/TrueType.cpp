//
// Created by 22753 on 2024/4/26.
//

#include "TrueType.h"
#include <Readers/Readers.h>
#include "Tables.h"
#include <memory>

using namespace font::reader;

string readtag(uint32_t input) {
    char *chars = new char[5];
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
    for (int i = 0; i < font_direction.numTables; i++) {
        auto table = std::make_shared<TableDirection>(readTableDirection(font_file));
        table_direction[readtag(table->tag)] = table;
    }

    font_file.seekg(table_direction.at("maxp")->offset);
    numGlyphs =  readnumGlyphs(font_file);
}

auto TrueType::gethead() -> head {
    auto table = table_direction.at("head");
    font_file.seekg(table->offset);
    auto m_head = readhead(font_file);
    return m_head;
}

auto TrueType::getloca() -> font::table::loca {
    auto table = table_direction.at("loca");
    font_file.seekg(table->offset);
    auto m_loca = readloca(font_file, numGlyphs);
    return m_loca;
}

auto TrueType::getGlyphs(uint16_t index) -> font::table::Glyphs {
    auto table = table_direction.at("glyf");
    font_file.seekg(table->offset + getloca().offsetAt(index));
    auto m_glyphs = Glyphs();
    m_glyphs.glyphs_des = readGlyphsDes(font_file);
    if (m_glyphs.glyphs_des.numberOfContours <= 0) return m_glyphs;
    m_glyphs.glyphs_data = readGlyphsData(font_file, m_glyphs.glyphs_des.numberOfContours);
    return m_glyphs;
}

auto TrueType::getcmap() -> font::table::cmap {
    int offset = table_direction.at("cmap")->offset;
    font::table::cmap table(font_file,offset);
    return table;
}

