#ifndef CHILDREN_CIRCLE_H
#define CHILDREN_CIRCLE_H

#include "Node.h"
#include <fstream>
#include <string>

class ChildrenCircle {
private:
    ChildNode* Head;
    int Size;

public:
    ChildrenCircle();
    ~ChildrenCircle();

    void AddChild(std::string& Name);
    void RemoveChild(ChildNode* Child);
    bool IsEmpty();
    void ProcessCounting(const std::string& InputFilename, const std::string& OutputFilename);
};

#endif