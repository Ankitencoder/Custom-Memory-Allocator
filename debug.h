#ifndef DEBUG_H
#define DEBUG_H

#include "allocator.h"

class Debug {
public:
    static void printMemoryLayout(Block* head);
};

#endif
