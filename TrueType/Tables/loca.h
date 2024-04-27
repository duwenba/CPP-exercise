#pragma once

#include <vector>


namespace font::table{
	class loca {
    protected:
        typedef  uint32_t OffsetType;
        typedef  vector<uint32_t> OffsetTable;
        OffsetTable offsets;
    public:
        loca() = default;
        explicit loca(uint32_t length) {
            offsets.reserve(length);
        }

        OffsetTable * getOffsets() {
            return &offsets;
        }

        OffsetType & offsetAt(uint16_t index){
            return offsets.at(index);
        }
	};

    class Sloca  {
    protected:
        typedef  uint16_t OffsetType;
        typedef  vector<uint16_t> OffsetTable;
        OffsetTable offsets;

    public:
        Sloca()= default;
        explicit Sloca(uint16_t length){
            offsets.reserve(length);
        }
    };
}
