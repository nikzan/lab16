#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "Node.h"
#include <fstream>
#include <string>

class CircularList {
private:
    Node* Head;
    int Size;

public:
    CircularList();
    ~CircularList();

    void Add(int Value);
    void Remove(Node* NodeToRemove);
    void Print();
    bool IsEmpty();
    void WriteToFile(std::string& Filename);
    Node* GetHead();
};

#endif
