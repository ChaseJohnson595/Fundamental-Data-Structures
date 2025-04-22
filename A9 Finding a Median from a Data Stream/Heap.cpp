#include <iomanip>
#include <cmath>
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
    elements[1] = elements[elements.size() - 1];
    int root_data = elements[1];
    int position = 1;

    // 2. pop_back() to remove the duplicate while maintaining the complete binary tree
    elements.pop_back();

    // 3. Loop continuation:
        // a.  if the parent's value > left child's or right child's, the smaller of children must be swapped with the parent
    while (elements[position*2] && (elements[position] > elements[position * 2] || elements[position] > elements[position * 2 + 1]))
    {
        if (elements[position] > elements[position * 2])
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

    // 4. Exit Condition:
        // a. if the parent's value < both children
        // b. if the parent becomes a leaf --> no children

}

int Heap::removeMin()
{
    // Case 0: No elements
    if (elements.size() == 1)
        return -1;                                              // Change to exception handling instead of returning negative

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

int Heap::getSize()
{
    return elements.size();
}

int Heap::getRoot()
{
    return elements[1];
}

ostream& operator<<(ostream& out, const Heap h)
{
    /*
    for (int i = 1; i <= h.elements.size(); i++)
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