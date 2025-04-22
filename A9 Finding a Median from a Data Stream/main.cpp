#include <iostream>
#include <cmath>
#include <vector>
#include "Node.h"
#include "MinHeap.h"

int main()
{
    std::vector<Node<int>*> nodes = {};
    
    nodes.push_back(new Node<int>(1, nullptr, 10));
    nodes.push_back(new Node<int>(2, nullptr, 20));
    nodes.push_back(new Node<int>(3, nullptr, 30));
    nodes.push_back(new Node<int>(4, nullptr, 40));
    nodes.push_back(new Node<int>(5, nullptr, 15));
    nodes.push_back(new Node<int>(6, nullptr, 60));
    nodes.push_back(new Node<int>(7, nullptr, 70));


    MinHeap<int> mHeap(nodes);

    mHeap.print();


    return 0;
}