//
// Created by 22753 on 2024/4/26.
//

#ifndef TRUETYPE_TRUETYPE_H
#define TRUETYPE_TRUETYPE_H

#include "FontDirection.h"
#include <iostream>
#include <fstream>
#include <string>


class TrueType {
private:
    //字体文件路径
    std::string font_path;
    //字体文件指针
    std::ifstream font_file;
    //FontDirection
    FontDirection font_direction;

public:
    TrueType(std::string font_path);

    ~TrueType();


};


#endif //TRUETYPE_TRUETYPE_H
