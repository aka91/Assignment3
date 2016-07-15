#include <iostream>
#include <string>
#include "Tree.h"
#include "Node.h"

using namespace std;

// Constructor
Tree::Tree() 
{
     root = NULL;
	 wordCount = 0;
}

Node* Tree::Root() 
{ 
	return root; 
}

// Destructor
Tree::~Tree() 
{
     deleteNode(root);
}

// Free the node
void Tree::deleteNode(Node* leaf)
{
    if ( leaf != NULL )
    {
       deleteNode(leaf->getLeft());
       deleteNode(leaf->getRight());
       delete leaf;
    }
}

int Tree::getWordCount()
{
	return wordCount;
}

// Add a node
void Tree::addNode(string EngWord, string KlinWord) 
{
     // No elements. Add the root
     if ( root == NULL ) {
        //cout << "add root node ... " << EngWord << KlinWord << endl;
        Node* n = new Node();
        n->setEngWord(EngWord);
		n->setKlinWord(KlinWord);
        root = n;
		wordCount++;
     }
     else 
	 {
       //cout << "add other node ... " << EngWord << KlinWord << endl;
       addNode(EngWord, KlinWord, root);
	   wordCount++;
     }
}

// Add a node (private)
void Tree::addNode(string EngWord, string KlinWord, Node* leaf) 
{
    if (EngWord < leaf->getEngWord() ) 
	{
       if ( leaf->getLeft() != NULL )
	   {
          addNode(EngWord, KlinWord, leaf->getLeft());
		  wordCount;
	   }
       else 
	   {
          Node* n = new Node();
          n->setEngWord(EngWord);
		  n->setKlinWord(KlinWord);
          leaf->setLeft(n);
		  wordCount++;
       }
    }
	/*
	else if (EngWord == leaf->getEngWord()) //Results in "bad_alloc at memory location"
	{
		deleteNode(root);
	}
	*/
    else 
	{
       if ( leaf->getRight() != NULL )
	   {
          addNode(EngWord, KlinWord, leaf->getRight());
		  wordCount++;
	   }
       else 
	   {
          Node* n = new Node();
          n->setEngWord(EngWord);
		  n->setKlinWord(KlinWord);
          leaf->setRight(n);
		  wordCount++;
       }
    }
}

void Tree::print(Node* n) 
{
    if (n != NULL) 
	{
       print(n->getLeft());
	   cout << n->getEngWord() << ": " << n->getKlinWord() << endl;
       print(n->getRight());
    }
}

bool Tree::search(string EngWord)
{
	if(EngWord == root->getEngWord())
	{
		return true;

	}
	else if(EngWord < root->getEngWord())
	{
		if (root->getLeft() == NULL)
		{
			return false;
			//cout << "Word not found" << endl;
		}
		else
		{
			root = root->getLeft();
			search(EngWord);
			//return false;
		}
	}
	else if(EngWord > root->getEngWord())
	{
		if (root->getRight() == NULL)
		{
			return false;
			//cout << "Word not found" << endl;
		}
		else
		{
			root = root->getRight();
			search(EngWord);
			//return false;
		}
	}
	else
	{
		return false;
		//cout << "Word not found" << endl;
	}

}


void Tree::printKlinWord() 
{
	cout << root->getKlinWord();
}
