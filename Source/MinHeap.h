#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED

#include "Node.h"
#include <iostream>
#include <vector>

class Heap
{
private:
    std::vector<Node*> items;
    int current_item_count;

public:
    Heap(int max_heap_size);

    void add(Node* node);

    void sortUp(Node* item);
    void sortDown(Node* item);

    void swapItems(Node* itemA, Node* itemB);

    Node* removeFirst();

    void updateItem(Node* item);

    bool contains(Node* item);

    int count() { return current_item_count; }

    void displayHeap();
};

#endif // MINHEAP_H_INCLUDED
