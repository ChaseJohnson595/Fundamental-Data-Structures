#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "Heap.h"

class MaxHeap : public Heap
{
protected:
    virtual void upHeap();
    virtual void downHeap();
public:
    int removeMax();
};



#endif