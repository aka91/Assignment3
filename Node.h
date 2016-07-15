/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of Event class type.
 *
 * Created on: 
 * Author: 
 */
 
// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _NODE and #define _NODE
#pragma once

#include <cstddef>  // defines NULL
#include <string>

using namespace std;

/*
class Node
{
public:
	// Public attributes - Why are the attributes public?
	
	Node* left;   // Pointer to next node
	Node* right;
	
	// Constructors and destructor
	Node();
	Node(string aEngWord, string aKlinWord);

	//~Node();

	string EngWord;
	string KlinWord;

}; // end Node



*/




class Node {
    string EngWord;
	string KlinWord;
    Node* left;
    Node* right;
public:
    Node();
	string getEngWord();
	string getKlinWord();
    void setEngWord(string aEngWord);
	void setKlinWord(string aKlinWord);
    void setLeft(Node* aLeft);
    void setRight(Node* aRight);
    Node* getLeft();
    Node* getRight();
};
