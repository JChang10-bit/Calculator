// Name: Joseph Chang
// VUNetID: changj6
// Email Address: joseph.chang@vanderbilt.edu
// Class: CS 3251
// Date: 4/15/2020
// Honor Statement: I have not given or received unauthorized aid on this assignment
// Assignment Number: Assignment #7

#include "Composite_Factorial_Node.h"
#include "Visitor.h"

// Ctor
Composite_Factorial_Node::Composite_Factorial_Node(Component_Node* left)
    : Composite_Unary_Left_Node(left)
{
}

int Composite_Factorial_Node::item() const
{
    return '!';
}

// accept a visitor
void Composite_Factorial_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}
