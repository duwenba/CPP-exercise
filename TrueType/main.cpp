
#include <Readers/Readers.h>
#include <Tables/TrueType.h>
using font::reader::printHex;

int main(/*int argc, char* argv[]*/) {
    string file_path = /*(argc > 1) ? argv[1] :8*/ "../font/JetBrainsMono-Bold.ttf";
    cout << file_path << endl;
    // Create a font reader object
    TrueType arial(file_path);
    auto m_head = arial.gethead();
    printHex<uint16_t>(arial.numGlyphs,"numGlyphs");
    auto m_loca = arial.getloca();
    int n = 0;
    cout << "m_loca.offsetAt("<< n << ") = " << m_loca.offsetAt(n) << endl;


    // Read the glyphs
    arial.getGlyphs(0);
    return 0;
}