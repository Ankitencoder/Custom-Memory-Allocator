#include "debug.h"
#include <iostream>

void Debug::printMemoryLayout(Block* head) {
    Block* curr = head;

    while (curr) {
        std::cout << "[Size: " << curr->size
                  << " | Free: " << curr->free << "] -> ";
        curr = curr->next;
    }

    std::cout << "NULL\n";
}
