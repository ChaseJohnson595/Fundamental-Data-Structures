#include <iostream>
#include <cmath>
#include <vector>
#include "Node.h"
#include "MinHeap.h"
#include "MaxHeap.h"

int main()
{
    std::vector<Node<int>*> nodes = {};

    for (int i = 0; i < 7; i++)
    {
        nodes.push_back(new Node<int>(i+1, nullptr, i));
    }

    MinHeap<int> mHeap(nodes);

    


    return 0;
}