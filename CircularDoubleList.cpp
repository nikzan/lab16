#include "CircularDoubleList.h"
#include <iostream>

CircularDoubleList::CircularDoubleList() : Head(nullptr), Size(0) {
}

CircularDoubleList::~CircularDoubleList() {
    if (!Head) {
        return;
    }

    DoubleNode* Current = Head;
    DoubleNode* Next;

    do {
        Next = Current->Next;
        delete Current;
        Current = Next;
    } while (Current != Head);
}

void CircularDoubleList::Add(int Value) {
    DoubleNode* NewNode = new DoubleNode(Value);

    if (!Head) {
        Head = NewNode;
        Head->Next = Head;
        Head->Prev = Head;
    }
    else {
        DoubleNode* Tail = Head->Prev;

        Tail->Next = NewNode;
        NewNode->Prev = Tail;
        NewNode->Next = Head;
        Head->Prev = NewNode;
    }

    Size++;
}

void CircularDoubleList::Remove(DoubleNode* NodeToRemove) {
    if (!Head) {
        return;
    }

    if (Head == NodeToRemove && Head->Next == Head) {
        delete Head;
        Head = nullptr;
        Size = 0;
        return;
    }

    NodeToRemove->Prev->Next = NodeToRemove->Next;
    NodeToRemove->Next->Prev = NodeToRemove->Prev;

    if (NodeToRemove == Head) {
        Head = Head->Next;
    }

    delete NodeToRemove;
    Size--;
}

void CircularDoubleList::Print() {
    if (!Head) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    DoubleNode* Current = Head;

    do {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    } while (Current != Head);

    std::cout << std::endl;
}

bool CircularDoubleList::IsEmpty() {
    return Head == nullptr;
}

DoubleNode* CircularDoubleList::GetHead() {
    return Head;
}

DoubleNode* CircularDoubleList::RemoveSurrounded() {
    if (!Head || Head->Next == Head) {
        return Head;
    }

    DoubleNode* Current = Head;
    bool HasRemoved = false;

    do {
        DoubleNode* NextNode = Current->Next;

        if (Current->Prev->Data == Current->Next->Data) {
            DoubleNode* ToRemove = Current;
            Current = NextNode;
            Remove(ToRemove);
            HasRemoved = true;
        }
        else {
            Current = NextNode;
        }
    } while (Current != Head);

    if (HasRemoved) {
        return Head->Prev;
    }
    else {
        return Head->Prev;
    }
}