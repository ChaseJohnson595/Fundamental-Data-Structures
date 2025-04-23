#include "MaxHeap.h"
#include <iostream>

void MaxHeap::upHeap()
{
    int new_data = elements.back();
    //int new_data = elements[elements.size() -1];

    int position = elements.size()-1;
    while (position > 1 && elements[position/2] < new_data)
    {
        // 1. bring down the parent's value to position
        elements[position] = elements[position/2];

        // 2. update position to position/2
        position = position / 2;
    }

    elements[position] = new_data;
}

void MaxHeap::downHeap()
{
    // 1. Copy the last element to the root position
    elements[1] = elements[elements.size() - 1];
    int root_data = elements[1];
    int position = 1;

    // 2. pop_back() to remove the duplicate while maintaining the complete binary tree
    elements.pop_back();

    // 3. Loop continuation:
        // a.  if the parent's value > left child's or right child's, the smaller of children must be swapped with the parent
    
    int size = elements.size() - 1;
    while (position * 2 <= size)
    {   
        int left = position * 2;                                    // Position of the left child
        int right = (position * 2) + 1;                               // Position of the right child
        int largerChild = left;                                     // Assuming there might only be a left child, set the smaller to the left

        if (right <= size && elements[right] > elements[left])      // If there is a right child AND it's smaller than the left, set it as the smallerChild
        {
            largerChild = position * 2 + 1;
        }

        if (root_data < elements[largerChild])
        {
            elements[position] = elements[largerChild];
            position = largerChild;
        }
        else
        {
            break;
        }
    }

    elements[position] = root_data;
    
    /*
    while (elements[position*2] && (elements[position] < elements[position * 2] || elements[position] < elements[position * 2 + 1]))
    {
        if (elements[position] < elements[position * 2])
        {
            elements[position] = elements[position * 2];
            position *= 2;
            elements[position] = root_data;
        }
        else 
        {
            elements[position] = elements[position * 2 + 1];
            position = position * 2 + 1;
            elements[position] = root_data;
        }
    }
    */
}

int MaxHeap::removeMax()
{
    // Case 0: No elements
    if (elements.size() == 1)
        return -1;

    // Case 1: Only one element in the heap
    int max_value = elements[1];
    if (elements.size() == 2)
    {
        elements.pop_back();
        return max_value;
    }

    // Case 2: more than one element in the heap --> downHeap
    else if (elements.size() > 2)
        downHeap();

    return max_value;
}