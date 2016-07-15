/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of Event class type.
 *
 * Created on: 
 * Author: 
 */

#include "Node.h"
#include <iostream>

using namespace std;
/*
Node::Node()
{
	left = right = NULL;
}

Node::Node(string aEngWord, string aKlinWord)
{
	left = right = NULL;
	EngWord = aEngWord;
	KlinWord = aKlinWord;
}


// end Node.cpp

*/

Node::Node() 
{
	EngWord = "";
	KlinWord = ""; 
	left=NULL; 
	right=NULL; 
}

string Node::getEngWord()
{
	return EngWord;
}

string Node::getKlinWord()
{
	return KlinWord;
}

void Node::setEngWord(string aEngWord)
{ 
	EngWord = aEngWord; 
}

void Node::setKlinWord(string aKlinWord)
{ 
	KlinWord = aKlinWord; 
}

void Node::setLeft(Node* aLeft) 
{ 
	left = aLeft; 
}

void Node::setRight(Node* aRight) 
{ 
	right = aRight; 
}

Node* Node::getLeft() 
{ 
	return left; 
}

Node* Node::getRight() 
{ 
	return right; 
}

