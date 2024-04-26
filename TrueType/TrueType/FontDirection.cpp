//
// Created by 22753 on 2024/4/26.
//

#include "FontDirection.h"

FontDirection::FontDirection(std::basic_ifstream<char> infile)  {
    // TODO: Implement this method
    // Read the scaler type from the font file
    scalerType = infile.read();


}
