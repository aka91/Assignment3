#pragma once
#include <string>
//#include "BinarySearchTree.cpp"
#include "Node.h"

using namespace std;


class Tree {
     Node* root;
	 int wordCount;
public:
     Tree();
     ~Tree();
     Node* Root();
	 int getWordCount();
     void addNode(string EngWord, string KlinWord);
     void print(Node* n);
	 //bool search(string EngWord);
	 //void printKlinWord();

     //void preOrder(Node* n);
     //void postOrder(Node* n);
private:
     void addNode(string EngWord, string KlinWord, Node* leaf);
     void deleteNode(Node* leaf);
};

