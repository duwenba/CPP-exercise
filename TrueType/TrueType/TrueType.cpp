//
// Created by 22753 on 2024/4/26.
//

#include "TrueType.h"

#include <utility>

TrueType::TrueType(std::string font_path) : font_path(std::move(font_path)) {
    font_file = std::ifstream(font_path, std::ios::binary);
    if (!font_file.is_open()) {
        throw std::runtime_error("Failed to open font file: " + font_path);
    }
    font_file.seekg(0, std::ios::end);
    font_direction = FontDirection(font_file);

}