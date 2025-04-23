#include <iostream>
#include <vector>
#include "Heap.h"
#include "MaxHeap.h"


int main()
{
    Heap minHeap;
    MaxHeap maxHeap;

    std::vector<int> input = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};

    for (int i = 0; i < input.size(); i++)
    {
        if (minHeap.getSize() > 1 && input[i] > minHeap.getRoot())
        {
            minHeap.insert(input[i]);
        }
        else
        {
            maxHeap.insert(input[i]);
        }

        if (minHeap.getSize() - maxHeap.getSize() == 2)
        {
            maxHeap.insert(minHeap.removeMin());
        }
        else if (maxHeap.getSize() - minHeap.getSize() == 2)
        {
            minHeap.insert(maxHeap.removeMax());
        }        
    }

    std::cout << "\nMin: " << std::endl << minHeap << std::endl;
    std::cout << "Max: " << std::endl << maxHeap << std::endl;
    
    if (minHeap.getSize() == maxHeap.getSize())
    {
        double median = (static_cast<double>(minHeap.getRoot()) + static_cast<double>(maxHeap.getRoot())) / 2;
        std::cout << "Median: " << median << std::endl << std::endl; 
    }
    else if (minHeap.getSize() > maxHeap.getSize())
    {
        std::cout << "Median: " << minHeap.getRoot() << std::endl << std::endl; 
    }
    else 
    {
        std::cout << "Median: " << maxHeap.getRoot() << std::endl << std::endl;
    }

    return 0;
}