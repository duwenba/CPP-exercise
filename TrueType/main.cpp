
//#include <iostream>
//#include <Readers/Readers.h>
#include <Tables/TrueType.h>
//using namespace font::reader;
int main() {
    // Create a font reader object
    TrueType arialReader("arial.ttf");
    auto mhead = arialReader.gethead();
    return 0;
}