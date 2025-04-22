#include <iostream>
#include "Heap.h"

int main()
{
    Heap minHeap;

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(30);
    minHeap.insert(40);
    minHeap.insert(15);

    std::cout << minHeap << std::endl;

    return 0;
}