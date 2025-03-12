#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "Node.h"

class DoubleLinkedList {
private:
    DoubleNode* Head;
    DoubleNode* Tail;
    int Size;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void Add(int Value);
    void Remove(DoubleNode* NodeToRemove);
    void Print();
    bool IsEmpty();

    DoubleNode* GetHead();
    DoubleNode* GetTail();
    void SetHead(DoubleNode* NewHead);
    void SetTail(DoubleNode* NewTail);

    DoubleNode* ReorderOdd();
    DoubleNode* ConvertToCircular();
};

#endif