#include "allocator.h"
#include "debug.h"
#include <iostream>

int main() {
    Allocator alloc;

    int* a = (int*)alloc.allocate(5 * sizeof(int));
    int* b = (int*)alloc.allocate(10 * sizeof(int));

    alloc.deallocate(a);
    alloc.deallocate(b);

    std::cout << "Memory allocated and freed successfully\n";

    return 0;
}
