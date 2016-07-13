/*
 * BinarySearchTree.h (and BinarySearchTree.cpp)
 * 
 * Class Description: A data collection ADT class to satisfy Assn 3's requiremetns.
 * Class invariants: FIFO or LILO  
 * Inspired on: June 18, 2016
 * Group: AC Solutions
 */

#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;


BinarySearchTree::BinarySearchTree()
{
	wordCount = 0;
	root = NULL;
	

}

bool BinarySearchTree::isEmpty() const
{
	if (root == NULL) return true;
	else return false;
}

bool BinarySearchTree::insert(const string newEngWord, const string newKlinWord)
{
	tree_node* t = new tree_node;
	tree_node* parent;

	t->EngWord = newEngWord;
	t->KlinWord = newKlinWord;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	
	
	if(BinarySearchTree::isEmpty() == true)
	{
		root = t;
		wordCount++;
		cout << "test1";
		return true;
	}
	else
	{
		tree_node* curr;
		curr = root;

		while(curr)
		{
			parent = curr;
			if(t->EngWord > curr->EngWord) //Doesn't leave this loop after the first time
			{
				curr = curr->right;
				wordCount++;
				cout << "test6";
				return true;
			}
			else curr = curr->left;
			wordCount++;
			cout << "test2";
			return true;
		}

		if(curr->EngWord > t->EngWord)
		{
			parent->left = t;
			cout << "test4";
			wordCount++;
			return true;
		}
		else 
			parent->right = t;
			wordCount++;
			cout << "test3";
			return true;
		
	}
	

}

int BinarySearchTree::getWordCount() const
{
	return wordCount;
}

string BinarySearchTree::getEngWord() const
{
	return root->EngWord;
}


void BinarySearchTree::display()
{
	inorder(root);
}

void BinarySearchTree::inorder(tree_node* p)
{
	
	if(p != NULL)
	{
		cout << p->EngWord << p->KlinWord << endl;
	}
	/*
	if(p != NULL)
	{
		if(p->left)
		{
			inorder(p->left);
		}
		cout << " " << p->EngWord << ": " << p->KlinWord << endl;

		if (p->right)
		{
			inorder(p->right);
		}
	}
	*/
	else return;
}

inline bool operator < (const BinarySearchTree& lhs, const BinarySearchTree& rhs) //Need to be able to access EngWord 
{
	return(lhs.getEngWord() < rhs.getEngWord() ); //Not the right comparison
															//Figure out how to compare strings!
}

inline bool operator > (const BinarySearchTree& lhs, const BinarySearchTree& rhs) 
{
	return operator< (rhs, lhs);
}


