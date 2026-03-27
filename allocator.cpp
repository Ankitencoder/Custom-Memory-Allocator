#include "allocator.h"
#include <unistd.h>

Allocator::Allocator() : head(nullptr) {}

Block* Allocator::findFreeBlock(size_t size) {
    Block* curr = head;
    while (curr) {
        if (curr->free && curr->size >= size)
            return curr;
        curr = curr->next;
    }
    return nullptr;
}

Block* Allocator::requestMemory(size_t size) {
    Block* block = (Block*)sbrk(sizeof(Block) + size);

    block->size = size;
    block->free = false;
    block->next = nullptr;

    if (!head) {
        head = block;
    } else {
        Block* curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = block;
    }

    return block;
}

void Allocator::split(Block* block, size_t size) {
    if (block->size <= size + sizeof(Block))
        return;

    Block* newBlock = (Block*)((char*)(block + 1) + size);

    newBlock->size = block->size - size - sizeof(Block);
    newBlock->free = true;
    newBlock->next = block->next;

    block->size = size;
    block->next = newBlock;
}

void* Allocator::allocate(size_t size) {
    Block* block = findFreeBlock(size);

    if (!block) {
        block = requestMemory(size);
    } else {
        block->free = false;
        split(block, size);
    }

    return (void*)(block + 1);
}

void Allocator::coalesce() {
    Block* curr = head;

    while (curr && curr->next) {
        if (curr->free && curr->next->free) {
            curr->size += sizeof(Block) + curr->next->size;
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
}

void Allocator::deallocate(void* ptr) {
    if (!ptr) return;

    Block* block = ((Block*)ptr) - 1;
    block->free = true;

    coalesce(); // merge adjacent free blocks
}
