#include "Node.h"
#include <string>

ChildNode::ChildNode(const std::string& ChildName) {
    Name = ChildName;
    Next = nullptr;
}

ChildNode::~ChildNode() {
}