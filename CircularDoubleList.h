#ifndef CIRCULAR_DOUBLE_LIST_H
#define CIRCULAR_DOUBLE_LIST_H

#include "Node.h"

class CircularDoubleList {
private:
    DoubleNode* Head;
    int Size;

public:
    CircularDoubleList();
    ~CircularDoubleList();

    void Add(int Value);
    void Remove(DoubleNode* NodeToRemove);
    void Print();
    bool IsEmpty();

    DoubleNode* GetHead();
    DoubleNode* RemoveSurrounded();
};

#endif