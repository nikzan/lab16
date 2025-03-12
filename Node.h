#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    int Data;
    Node* Next;

    Node(int Value): Data(Value), Next(nullptr) {
    }
};

class DoubleNode {
public:
    int Data;
    DoubleNode* Next;
    DoubleNode* Prev;

    DoubleNode(int Value): Data(Value), Next(nullptr), Prev(nullptr) {
    }
};

class ChildNode {
public:
    std::string Name;
    ChildNode* Next;

    ChildNode(const std::string& ChildName);
    ~ChildNode();
};

#endif