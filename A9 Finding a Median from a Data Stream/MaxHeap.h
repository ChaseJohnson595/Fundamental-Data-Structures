#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "Heap.h"

class MaxHeap : public Heap
{
protected:
    /**
     * Creates a MaxHeap that inherits from Heap (MinHeap) to avoid redundant code
     */
    virtual void upHeap();
    /**
     * Balances the heap by taking the last number in the heap and pushing it to the top, 
     * then filtering it downwards again until it reaches the correct location
     */
    virtual void downHeap();
public:
    /**
     * Removes the maximum node (the root node of the MinHeap) and returns it in heaps with 0 - 1 element, calls downHeap() if heap has more.
     * @return The value of the root node
     */
    int removeMax();
};



#endif