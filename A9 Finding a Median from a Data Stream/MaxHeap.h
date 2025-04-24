#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include "Heap.h"

template <typename T>
class MaxHeap : public Heap<T>
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
    T removeMax();

    class EmptyHeapException {};
};

template <typename T>
void MaxHeap<T>::upHeap()
{
    T new_data = Heap<T>::elements.back();
    //int new_data = Heap<T>::elements[Heap<T>::elements.size() -1];

    int position = Heap<T>::elements.size()-1;
    while (position > 1 && Heap<T>::elements[position/2] < new_data)
    {
        // 1. bring down the parent's value to position
        Heap<T>::elements[position] = Heap<T>::elements[position/2];

        // 2. update position to position/2
        position = position / 2;
    }

    Heap<T>::elements[position] = new_data;
}

template <typename T>
void MaxHeap<T>::downHeap()
{
    // 1. Copy the last element to the root position
    Heap<T>::elements[1] = Heap<T>::elements[Heap<T>::elements.size() - 1];
    int root_data = Heap<T>::elements[1];
    int position = 1;

    // 2. pop_back() to remove the duplicate while maintaining the complete binary tree
    Heap<T>::elements.pop_back();

    // 3. Loop continuation:
        // a.  if the parent's value > left child's or right child's, the smaller of children must be swapped with the parent
    
    int size = Heap<T>::elements.size() - 1;
    while (position * 2 <= size)
    {   
        int left = position * 2;                                    // Position of the left child
        int right = (position * 2) + 1;                             // Position of the right child
        int largerChild = left;                                     // Assuming there might only be a left child, set the smaller to the left

        if (right <= size && Heap<T>::elements[right] > Heap<T>::elements[left])      // If there is a right child AND it's smaller than the left, set it as the smallerChild
        {
            largerChild = position * 2 + 1;
        }

        if (root_data < Heap<T>::elements[largerChild])
        {
            Heap<T>::elements[position] = Heap<T>::elements[largerChild];
            position = largerChild;
        }
        else
        {
            break;
        }
    }

    Heap<T>::elements[position] = root_data;
}

template <typename T>
T MaxHeap<T>::removeMax()
{
    // Case 0: No Heap<T>::elements
    if (Heap<T>::elements.size() == 1)
    {
        throw EmptyHeapException();
    }
    

    // Case 1: Only one element in the heap
    T max_value = Heap<T>::elements[1];
    if (Heap<T>::elements.size() == 2)
    {
        Heap<T>::elements.pop_back();
        return max_value;
    }

    // Case 2: more than one element in the heap --> downHeap
    else if (Heap<T>::elements.size() > 2)
        downHeap();

    return max_value;
}

#endif