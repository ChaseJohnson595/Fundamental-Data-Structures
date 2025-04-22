#ifndef HEAP_H
#define HEAP_H
#include <ostream>
#include <vector>

using namespace std;

class Heap
{
protected:
    vector<int> elements;
    virtual void upHeap();
    virtual void downHeap();
public:
    Heap();
    void insert(int);
    int  removeMin();   // no parameter --> return the value at the root
    int  getRoot();

    // If the left operand is not heap type, the operator cannot be a member
    friend ostream& operator<<(ostream&, const Heap);
};

#endif