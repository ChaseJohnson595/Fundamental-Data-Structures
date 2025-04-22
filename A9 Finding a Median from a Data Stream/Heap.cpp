#include "Heap.h"

Heap::Heap()
{
    elements.push_back(-1); // -1: invalid assuming all positive data
}

void Heap::insert(int new_data)
{
    elements.push_back(new_data);

    // Case 1: only one element --> root
    if ((elements.size() - 1) == 1)
        return;

    // Case 2: at least two elements in the heap -> upHeap or percolateUp
    upHeap();

}

void Heap::upHeap()
{
    //int newData = elements.back();
    int new_data = elements[elements.size() -1];

    int position = elements.size()-1;
    while (position > 1 && elements[position/2] > new_data)
    {
        // 1. bring down the parent's value to position
        elements[position] = elements[position/2];

        // 2. update position to position/2
        position = position / 2;
    }

    elements[position] = new_data;
}

void Heap::downHeap()
{
    // 1. Copy the last element to the root position

    // 2. pop_back() to remove the duplicate while maintaining the complete binary tree

    // 3. Loop continuation:
        // a.  if the parent's value > left child's or right child's, the smaller of children must be swapped with the parent

    // 4. Exit Condition:
        // a. if the parent's value < both children
        // b. if the parent becomes a leaf --> no children

}

int Heap::removeMin()
{
    // Case 0: No elements
    if (elements.size() == 1)
        return -1;

    // Case 1: Only one element in the heap
    int min_value = elements[1];
    if (elements.size() == 2)
    
    // Case 2: more than one element in the heap --> downHeap
    downHeap();

    return min_value;


}