// Name: Joseph Chang
// VUNetID: changj6
// Email Address: joseph.chang@vanderbilt.edu
// Class: CS 3251
// Date: 4/15/2020
// Honor Statement: I have not given or received unauthorized aid on this assignment
// Assignment Number: Assignment #7

#include "Composite_Unary_Left_Node.h"

// Ctor
Composite_Unary_Left_Node::Composite_Unary_Left_Node(Component_Node* left)
    : Component_Node()
    , leftChild(left)
{
}

// Return the left child pointer
Component_Node* Composite_Unary_Left_Node::left() const
{
    return leftChild.get();
}
