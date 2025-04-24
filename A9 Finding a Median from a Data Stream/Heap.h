#ifndef HEAP_H
#define HEAP_H
#include <ostream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

template <typename T>
class Heap
{
protected:
    vector<T> elements;
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
    void insert(T);
    
    /**
     * Removes the minimum node (the root node of the MinHeap) and returns it in heaps with 0 - 1 element, calls downHeap() if heap has more.
     * @return The value of the root node
     */
    T  removeMin();   // no parameter --> return the value at the root
    
    /**
     * Gets the size of the heap
     * @return The size of the heap
     */
    T  getSize();

    /**
     * Gets the value of the root of the heap
     * @return The root value
     */
    T  getRoot();

    // If the left operand is not heap type, the operator cannot be a member
    /**
     * Overloads the << operator to allow cout to print a heap without using a print function
     * @param out The output stream you want to feed everything to be printed to
     * @param h The heap constant you'd like to print
     * @return The completed output stream containing the printed heap
     */
    template <typename U>
    friend ostream& operator<<(ostream&, const Heap<U>);

    class EmptyHeapException {};
};


template <typename T>
Heap<T>::Heap()
{
    elements.push_back(-1); // -1: invalid assuming all positive data
}

template <typename T>
void Heap<T>::insert(T new_data)
{
    elements.push_back(new_data);

    // Case 1: only one element --> root
    if ((elements.size() - 1) == 1)
        return;

    // Case 2: at least two elements in the heap -> upHeap or percolateUp
    upHeap();

}

template <typename T>
void Heap<T>::upHeap()
{
    //int newData = elements.back();
    int new_data = elements[elements.size() -1];                            // Creating a local variable for the new data

    int position = elements.size()-1;
    while (position > 1 && elements[position/2] > new_data)                 // While correct position hasn't been found, keep pushing it up
    {
        // 1. bring down the parent's value to position
        elements[position] = elements[position/2];

        // 2. update position to position/2
        position = position / 2;
    }

    elements[position] = new_data;
}

template <typename T>
void Heap<T>::downHeap()
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
        // Determining the smaller child
        int left = position * 2;                                    // Position of the left child
        int right = position * 2 + 1;                               // Position of the right child
        int smallerChild = left;                                    // Assuming there might only be a left child, set the smaller to the left

        if (right <= size && elements[right] < elements[left])      // If there is a right child AND it's smaller than the left, set it as the smallerChild
        {
            smallerChild = right;
        }

        // Swapping the elements
        if (root_data > elements[smallerChild])                     // If the original data is larger than the next child, replace the parent with the child
        {
            elements[position] = elements[smallerChild];
            position = smallerChild;
        }
        else
        {
            break;
        }
    }
    
    elements[position] = root_data;
}

template <typename T>
T Heap<T>::removeMin()
{
    // Case 0: No elements
    if (elements.size() == 1)
        throw EmptyHeapException();                                              // Change to exception handling instead of returning negative
    
    
    // Case 1: Only one element in the heap
    int min_value = elements[1];

    if (elements.size() == 2)
    {
        elements.pop_back();
        return min_value;
    }

    // Case 2: more than one element in the heap --> downHeap
    downHeap();

    return min_value;
}

template <typename T>
T Heap<T>::getSize()
{
    return elements.size();
}

template <typename T>
T Heap<T>::getRoot()
{
    return elements[1];
}

template <typename T>
ostream& operator<<(ostream& out, const Heap<T> h)
{
    /*
    for (int i = 1; i <= h.elements.size()-1; i++)
    {
        out << h.elements[i] << " ";
    }
    out << endl;
    */
    
    int n = h.elements.size() - 1;
    if (n == 0) {
        out << "Heap is empty.\n";
        return out;
    }

    int levels = std::log2(n) + 1;
    int index = 0;

    for (int level = 0; level < levels; ++level) {
        int nodesInLevel = std::pow(2, level);
        int startIdx = std::pow(2, level) - 1;
        int endIdx = std::min((int)std::pow(2, level + 1) - 2, n - 1);

        // Calculate spacing
        int totalWidth = std::pow(2, levels) * 2;
        int spaceBetween = totalWidth / (nodesInLevel + 1);

        // Print nodes at current level
        for (int i = startIdx; i <= endIdx && i < n; ++i) {
            out << std::setw(spaceBetween) << h.elements[i+1];
        }
        out << "\n";
    }
    
    return out;
}

#endif