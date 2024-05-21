
#include <Readers/Readers.h>
#include <Tables/TrueType.h>

void printGlyph(TrueType &arial, int n);

using font::reader::printHex;

auto main(int argc, char* argv[]) -> int {
    string file_path = (argc > 1) ? argv[1] : "../font/JetBrainsMono-Bold.ttf";
    cout << file_path << endl;
    // Create a font reader object
    TrueType arial(file_path);
    auto m_head = arial.gethead();
    printHex<uint16_t>(arial.numGlyphs,"numGlyphs");
    auto m_loca = arial.getloca();
    auto m_cmap = arial.getcmap();
//    auto A_index = m_cmap.findGlyphIndexInFormat4(0x0041);//A
//    auto B_index = m_cmap.findGlyphIndexInFormat4(0x0042);//B
//    auto C_index = m_cmap.findGlyphIndexInFormat4(0x0043);//C
//    auto D_index = m_cmap.findGlyphIndexInFormat4(0x0044);//D


    printGlyph(arial, 0);

//    printGlyph(arial, B_index);
//
//    printGlyph(arial, C_index);
//
//    printGlyph(arial, D_index);

    return 0;
}

void printGlyph(TrueType & arial,int n) {
    auto m_loca = arial.getloca();

    cout << "m_loca.offsetAt(" << n << ") = " << m_loca.offsetAt(n) << endl;


    // Read the glyphs
    auto glyph = arial.getGlyphs(n) ;
    if (glyph.glyphs_des.numberOfContours == -1) return;
    cout << "numberOfContours = " << glyph.glyphs_des.numberOfContours << endl;
    cout << "xMin = " << glyph.glyphs_des.xMin << endl;
    cout << "yMin = " << glyph.glyphs_des.yMin << endl;
    cout << "xMax = " << glyph.glyphs_des.xMax << endl;
    cout << "yMax = " << glyph.glyphs_des.yMax << endl;

    for(int i = 0; i < glyph.glyphs_des.numberOfContours; i++){
        cout << "contour[" << i << "].endPointIndex = " << glyph.glyphs_data.endPtsOfContours[i] << endl;
    }

    for ( int i = 0; i < glyph.glyphs_data.flags.size(); i++ ) {
        cout << "Point[" << setw(2) << i << "] : "
        << "(" << setw(3) << glyph.glyphs_data.xCoords[i]
        << "," << setw(4) << glyph.glyphs_data.yCoords[i] << ")"
        << endl;
    }
}
