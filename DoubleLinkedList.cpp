#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList() : Head(nullptr), Tail(nullptr), Size(0) {
}

DoubleLinkedList::~DoubleLinkedList() {
    DoubleNode* Current = Head;

    while (Current) {
        DoubleNode* Next = Current->Next;
        delete Current;
        Current = Next;
    }

}

void DoubleLinkedList::Add(int Value) {
    DoubleNode* NewNode = new DoubleNode(Value);

    if (!Head) {
        Head = NewNode;
        Tail = NewNode;
    }
    else {
        Tail->Next = NewNode;
        NewNode->Prev = Tail;
        Tail = NewNode;
    }

    Size++;
}

void DoubleLinkedList::Remove(DoubleNode* NodeToRemove) {
    if (!Head) {
        return;
    }

    if (NodeToRemove == Head && NodeToRemove == Tail) {
        delete NodeToRemove;
        Head = nullptr;
        Tail = nullptr;
        Size = 0;
        return;
    }

    if (NodeToRemove == Head) {
        Head = Head->Next;
        Head->Prev = nullptr;
    }
    else if (NodeToRemove == Tail) {
        Tail = Tail->Prev;
        Tail->Next = nullptr;
    }
    else {
        NodeToRemove->Prev->Next = NodeToRemove->Next;
        NodeToRemove->Next->Prev = NodeToRemove->Prev;
    }

    delete NodeToRemove;
    Size--;
}

void DoubleLinkedList::Print() {
    if (!Head) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    DoubleNode* Current = Head;

    while (Current) {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }

    std::cout << std::endl;
}

bool DoubleLinkedList::IsEmpty() {
    return Head == nullptr;
}

DoubleNode* DoubleLinkedList::GetHead() {
    return Head;
}

DoubleNode* DoubleLinkedList::GetTail() {
    return Tail;
}

void DoubleLinkedList::SetHead(DoubleNode* NewHead) {
    Head = NewHead;
}

void DoubleLinkedList::SetTail(DoubleNode* NewTail) {
    Tail = NewTail;
}

DoubleNode* DoubleLinkedList::ReorderOdd() {
    if (!Head || !Head->Next) {
        return Head;
    }

    DoubleNode* EvenHead = Head;
    DoubleNode* OddHead = Head->Next;
    DoubleNode* EvenCurrent = EvenHead;
    DoubleNode* OddCurrent = OddHead;
    DoubleNode* Current = OddCurrent->Next;
    int Index = 2;

    while (Current) {
        if (Index % 2 == 0) {
            EvenCurrent->Next = Current;
            Current->Prev = EvenCurrent;
            EvenCurrent = Current;
        }
        else {
            OddCurrent->Next = Current;
            Current->Prev = OddCurrent;
            OddCurrent = Current;
        }

        Current = Current->Next;
        Index++;
    }

    EvenCurrent->Next = OddHead;
    OddHead->Prev = EvenCurrent;
    OddCurrent->Next = nullptr;

    Head = EvenHead;
    Tail = OddCurrent;

    return Head;
}

DoubleNode* DoubleLinkedList::ConvertToCircular() {
    DoubleNode* Barrier = new DoubleNode(0);

    if (!Head) {
        Barrier->Next = Barrier;
        Barrier->Prev = Barrier;
    }
    else {
        Barrier->Next = Head;
        Barrier->Prev = Tail;

        Head->Prev = Barrier;
        Tail->Next = Barrier;

        Head = nullptr;
        Tail = nullptr;
        Size = 0;
    }

    return Barrier;
}