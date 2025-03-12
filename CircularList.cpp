#include "CircularList.h"
#include <iostream>
#include <string>
#include <fstream>

CircularList::CircularList() : Head(nullptr), Size(0) {
}

CircularList::~CircularList() {
    if (!Head) {
        return;
    }

    Node* Current = Head;
    Node* Next;

    do {
        Next = Current->Next;
        delete Current;
        Current = Next;
    } while (Current != Head);
}

void CircularList::Add(int Value) {
    Node* NewNode = new Node(Value);

    if (!Head) {
        Head = NewNode;
        Head->Next = Head;
    }
    else {
        Node* Current = Head;
        while (Current->Next != Head) {
            Current = Current->Next;
        }

        Current->Next = NewNode;
        NewNode->Next = Head;
    }

    Size++;
}

void CircularList::Remove(Node* NodeToRemove) {
    if (!Head) {
        return;
    }

    if (Head == NodeToRemove && Head->Next == Head) {
        delete Head;
        Head = nullptr;
        Size = 0;
        return;
    }

    Node* Current = Head;

    while (Current->Next != NodeToRemove) {
        Current = Current->Next;
    }

    if (NodeToRemove == Head) {
        Head = Head->Next;
    }

    Current->Next = NodeToRemove->Next;
    delete NodeToRemove;
    Size--;
}

void CircularList::Print() {
    if (!Head) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* Current = Head;

    do {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    } while (Current != Head);

    std::cout << std::endl;
}

bool CircularList::IsEmpty() {
    return Head == nullptr;
}

Node* CircularList::GetHead() {
    return Head;
}

void CircularList::WriteToFile(std::string& Filename) {
    std::ofstream File(std::string("../") + Filename);

    if (!File.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return;
    }

    if (!Head) {
        File.close();
        return;
    }

    Node* Current = Head;

    while (!IsEmpty()) {
        File << Current->Data << " ";

        Node* ToRemove = Current;

        if (Current->Next == Current) {
            Remove(Current);
            break;
        }
        else {
            Current = Current->Next;
        }

        Remove(ToRemove);

        for (int I = 0; I < 2 && !IsEmpty(); ++I) {
            Current = Current->Next;
        }
    }

    File.close();
}