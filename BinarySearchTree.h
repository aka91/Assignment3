/*
 * BinarySearchTree.h (and BinarySearchTree.cpp)
 * 
 * Class Description: A data collection ADT class to satisfy Assn 3's requiremetns.
 * Class invariants: FIFO or LILO  
 * Inspired on: June 18, 2016
 * Group: AC Solutions
 */

#pragma once
#include <string>
//#include "BinarySearchTree.cpp"
//#include "Node.h"

using namespace std;


class BinarySearchTree
{
private: 

	struct tree_node
	{
		tree_node* left;
		tree_node* right;
		string EngWord;
		string KlinWord;
		
	};

	tree_node* root;
	int wordCount;

public:

   // Default Constructor
   BinarySearchTree();
  
   //int getIndex;
  
   // Description: Returns "true" is this queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
   
   // Description: Adds newElement to a sorted tree
   //					smaller elements go left
   //					larger elements go right
   //					Returns "true" if inserted correctly, otherwise "false".
   // Time Efficiency: O(log n)
   bool insert(const string newEngWord, const string newKlinWord); //Might need to pass a pointer char&

   // Description: Returns number of words currently in tree
   // Time Efficiency: O(1)
   int getWordCount() const;

   string getEngWord() const;

   void display();

   void inorder(tree_node* p);

   //Need an overloaded < and > operators
   inline bool operator <(const BinarySearchTree& lhs);

   inline bool operator >(const BinarySearchTree& lhs);
  
};