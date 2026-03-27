#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstddef>

struct Block {
    size_t size;
    bool free;
    Block* next;
};

class Allocator {
private:
    Block* head;

    Block* findFreeBlock(size_t size);
    Block* requestMemory(size_t size);
    void coalesce();

public:
    Allocator();

    void* allocate(size_t size);
    void deallocate(void* ptr);

    void split(Block* block, size_t size);
};

#endif
