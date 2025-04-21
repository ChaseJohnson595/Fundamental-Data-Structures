#ifndef MINHEAP_H
#define MINHEAP_H
#include <vector>
#include <cmath>
#include "Node.h"

template <typename T>
class MinHeap
{
protected:
    std::vector<Node<T>*> minHeap;
public:
    MinHeap();
    MinHeap(std::vector<Node<T>*>);
    void push(Node<T>*);
    Node<T>* pop();
    Node<T>* peek();
    void print();
};

template <typename T>
MinHeap<T>::MinHeap()
{
    std::vector<Node<T>*> minHeap = {};
}

template <typename T>
MinHeap<T>::MinHeap(std::vector<Node<T>*> incomingVector)
{
    for (int i = 0; i < incomingVector.size(); i++)
    {
        this->push(incomingVector[i]);
    }
}

template <typename T>
void MinHeap<T>::push(Node<T>* nodeToAdd)
{
    if (this->minHeap.size() == 0)
    {
        this->minHeap.insert(minHeap.begin() + (nodeToAdd->position-1), nodeToAdd);
        return;
    }
    else
    {
        minHeap.insert(minHeap.begin() + (nodeToAdd->position-1), nodeToAdd);
        nodeToAdd->parent = this->minHeap[floor(nodeToAdd->position/2)-1];
    }
}

/*
template <typename T>
Node<T>* MinHeap<T>::pop()
{
    
}
*/
/*
template <typename T>
void MinHeap<T>::print()
{
    for (int i = 0; i < minHeap.size(); i++)
    {
        if (i == 0)
        {
            std::cout << minHeap[0]->data << std::endl;
            continue;
        }
        
        if 
    }
}
*/

#endif