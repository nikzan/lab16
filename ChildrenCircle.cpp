#include "ChildrenCircle.h"
#include <iostream>
#include <fstream>
#include <string>

ChildrenCircle::ChildrenCircle() : Head(nullptr), Size(0) {
}

ChildrenCircle::~ChildrenCircle() {
    if (!Head) {
        return;
    }

    ChildNode* Current = Head;
    ChildNode* Next;

    do {
        Next = Current->Next;
        delete Current;
        Current = Next;
    } while (Current != Head);
}

void ChildrenCircle::AddChild(std::string& Name) {
    ChildNode* NewNode = new ChildNode(Name);

    if (!Head) {
        Head = NewNode;
        Head->Next = Head;
    }
    else {
        ChildNode* Current = Head;

        while (Current->Next != Head) {
            Current = Current->Next;
        }

        Current->Next = NewNode;
        NewNode->Next = Head;
    }

    Size++;
}

void ChildrenCircle::RemoveChild(ChildNode* Child) {
    if (!Head) {
        return;
    }

    if (Head == Child && Head->Next == Head) {
        delete Head;
        Head = nullptr;
        Size = 0;
        return;
    }

    ChildNode* Current = Head;

    while (Current->Next != Child) {
        Current = Current->Next;
    }

    if (Child == Head) {
        Head = Head->Next;
    }

    Current->Next = Child->Next;
    delete Child;
    Size--;
}

bool ChildrenCircle::IsEmpty() {
    return Head == nullptr;
}

void ChildrenCircle::ProcessCounting(const std::string& InputFilename,
                                     const std::string& OutputFilename) {
    std::ifstream InFile(InputFilename);

    if (!InFile.is_open()) {
        std::cout << "Error opening input file!" << std::endl;
        return;
    }

    int Count;
    InFile >> Count;
    InFile.ignore();

    std::string Name;
    while (std::getline(InFile, Name)) {
        if (!Name.empty()) {
            AddChild(Name);
        }
    }

    InFile.close();

    std::ofstream OutFile(OutputFilename);

    if (!OutFile.is_open()) {
        std::cout << "Error opening output file!" << std::endl;
        return;
    }

    if (!Head) {
        OutFile.close();
        return;
    }

    ChildNode* Current = Head;

    while (!IsEmpty()) {
        for (int I = 1; I < Count; ++I) {
            Current = Current->Next;
        }

        OutFile << Current->Name << std::endl;

        ChildNode* Next = Current->Next;
        RemoveChild(Current);
        Current = Next;
    }

    OutFile.close();
}