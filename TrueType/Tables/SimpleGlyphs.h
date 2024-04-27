//
// Created by 22753 on 2024/4/27.
//

#ifndef TABLES_SIMPLEGLYPHS_H
#define TABLES_SIMPLEGLYPHS_H

namespace font::table{

    struct GlyphsDes {
        int16_t numberOfContours;
        int16_t xMin;
        int16_t yMin;
        int16_t xMax;
        int16_t yMax;
    };

    struct GlyphsData {
        vector<uint16_t> endPtsOfContours;
        uint16_t instructionLength;
        vector<uint8_t> instructions;
        vector<uint8_t> flags;
        vector<int16_t> xCoords;
        vector<int16_t> yCoords;
    };

    class Glyphs {
    public:
        GlyphsDes glyphs_des{};
        GlyphsData glyphs_data;
    };
}

#endif //TABLES_SIMPLEGLYPHS_H
