// Name: Joseph Chang
// VUNetID: changj6
// Email Address: joseph.chang@vanderbilt.edu
// Class: CS 3251
// Date: 4/15/2020
// Honor Statement: I have not given or received unauthorized aid on this assignment
// Assignment Number: Assignment #7

#include "Composite_Modulus_Node.h"
#include "Visitor.h"

// Ctor
Composite_Modulus_Node::Composite_Modulus_Node(Component_Node* left, Component_Node* right)
    : Composite_Binary_Node(left, right)
{
}

int Composite_Modulus_Node::item() const
{
    return '%';
}

// accept a visitor
void Composite_Modulus_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}