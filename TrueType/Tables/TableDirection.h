//
// Created by 22753 on 2024/4/26.
//

#ifndef TABLES_TABLEDIRECTION_H
#define TABLES_TABLEDIRECTION_H
#include<cstdint>

using namespace std;

namespace font::table {

    class TableDirection {
    public:
        uint32_t tag;
        uint32_t offset;
        uint32_t length;
    };
}

#endif //TABLES_TABLEDIRECTION_H
