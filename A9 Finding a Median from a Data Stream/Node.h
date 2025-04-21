#ifndef NODE_H
#define NODE_H


template <typename T>
class MinHeap;

template <typename T>
class MaxHeap;

template <typename T>
class Node
{
private:
    int position;
    Node* parent;
    T data;
public:
    Node(int, Node*, T);
    ~Node();
    
    friend class MinHeap<T>;
    friend class MaxHeap<T>;
};

template <typename T>
Node<T>::Node(int position, Node* parent, T data)
{
    this->position = position;
    this->parent = parent;
    this->data = data;
}

template <typename T>
Node<T>::~Node()
{
    std::cout << "~Node() called: " << this << std::endl;
}


#endif