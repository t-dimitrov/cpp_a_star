#include "MinHeap.h"

Heap::Heap(int max_heap_size)
{
    items = std::vector<Node*>(max_heap_size);
    current_item_count = 0;
}

void Heap::add(Node* item)
{
    item->heapIndex = current_item_count;
    items[current_item_count] = item;
    sortUp(item);
    current_item_count++;
}


void Heap::sortUp(Node* item)
{
    int parentIndex = (item->heapIndex - 1) / 2;

    while(true)
    {
        Node* parentItem = items[parentIndex];
        if(item->fCost() < parentItem->fCost())
        {
            swapItems(item, parentItem);
        }
        else
        {
            break;
        }

        parentIndex = (item->heapIndex - 1) / 2;
    }
}


void Heap::sortDown(Node* item)
{
    while(true)
    {
        int leftIndex = item->heapIndex * 2 + 1;
        int rightIndex = item->heapIndex * 2 + 2;
        int swapIndex = 0;

        if(leftIndex < current_item_count)
        {
            swapIndex = leftIndex;

            if(rightIndex < current_item_count)
            {
                if(items[leftIndex]->fCost() > items[rightIndex]->fCost())
                {
                    swapIndex = rightIndex;
                }
            }

            if(item->fCost() > items[swapIndex]->fCost())
            {
                swapItems(item, items[swapIndex]);
            }
            else
                return;

        }
        else
            return;
    }
}


Node* Heap::removeFirst()
{
    Node* firstItem = items[0];
    current_item_count--;
    items[0] = items[current_item_count];
    items[0]->heapIndex = 0;
    sortDown(items[0]);

    return firstItem;
}


void Heap::updateItem(Node* item)
{
    sortUp(item);
}


void Heap::swapItems(Node* itemA, Node* itemB)
{
    items[itemA->heapIndex] = itemB;
    items[itemB->heapIndex] = itemA;
    int itemAindex = itemA->heapIndex;
    itemA->heapIndex = itemB->heapIndex;
    itemB->heapIndex = itemAindex;
}


bool Heap::contains(Node* item)
{
    return items[item->heapIndex] == item ? true : false;
}


void Heap::displayHeap()
{
    for(int i = 0; i < current_item_count; i++)
    {
        std::cout << items[i]->position.x << ", " << items[i]->position.y << std::endl;
    }
}
