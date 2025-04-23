#ifndef HEAP_H
#define HEAP_H
#include <ostream>
#include <vector>

using namespace std;

class Heap
{
protected:
    vector<int> elements;
    /**
     * Balances the heap to place the new data in the correct location
     */
    virtual void upHeap();
    /**
     * Balances the heap by taking the last number in the heap and pushing it to the top, 
     * then filtering it downwards again until it reaches the correct location
     */
    virtual void downHeap();
public:
    /**
     * Creates an "empty" heap with a dummy variable at index [0] to allign position with indices
     */
    Heap();
    
    /**
     * Adds an element to the end of the heap, if the size is 2 or more after adding the new data, this function calls upHeap() to balance the heap.
     * @param new_data The data to add to the heap
     */
    void insert(int);
    
    /**
     * Removes the minimum node (the root node of the MinHeap) and returns it in heaps with 0 - 1 element, calls downHeap() if heap has more.
     * @return The value of the root node
     */
    int  removeMin();   // no parameter --> return the value at the root
    
    /**
     * Gets the size of the heap
     * @return The size of the heap
     */
    int  getSize();

    /**
     * Gets the value of the root of the heap
     * @return The root value
     */
    int  getRoot();

    // If the left operand is not heap type, the operator cannot be a member
    /**
     * Overloads the << operator to allow cout to print a heap without using a print function
     * @param out The output stream you want to feed everything to be printed to
     * @param h The heap constant you'd like to print
     * @return The completed output stream containing the printed heap
     */
    friend ostream& operator<<(ostream&, const Heap);
};

#endif