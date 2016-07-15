//  EKTApp.cpp
//  Assignment#3
//
//  Created by Alex Kim on 2016-07-15.
//  Copyright © 2016 DEVELOPED BY SFU COMPUTER SCIENSE STUDENTS. All rights reserved.
//
// File:        a1simpledriver.cpp
// Author:      Alex Kim
// Date:        2016-07-12
// Description: 
//              In general, please ensure that you test:
//               1. invalid parameter(s)
//               2. valid parameter(s), boundary case
//               3. valid parameter(s), general case

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
#include <locale>

// Include all header files here
#include "Tree.h"
#include "Node.h"

using namespace std;

int main(int argc, char *argv[])
{
 	//Populating the translator by opening the file and 
	char* filename = "dataFile.txt";
	string engword;
	string klinword;
	ifstream myfile (filename);

	Tree* b = new Tree();
	//b.insert("engword", "klinword");
	//b->addNode("Beta", "test1");
	//b->addNode("Alpha", "test3");

	//cout << "In order traversal" << endl;
	//b->inOrder(b->Root());
	//cout << endl;

	int numLoops = 0;
	//b.display();
	//cout <<"Current number of words in tree: " << b->getWordCount() << endl;
	//delete b;
	
	if (myfile.is_open())
	{
		
		string line;
		//char delimiter(':');
		char delimiter;

			while (getline(myfile, line))
			{
			  istringstream ss(line);
			  //ss >> engword >> delimiter >> klinword;
			  ss >> engword >> klinword; //Dont know if delimiter is necessary
			  //engword = engword + delimiter;
			  //cout << engword << klinword << endl;
			  //locale loc;
	
			  //b->insert(engword, klinword); //works

			  //b->display();

			  //Shouldn't do this when need to display
			  //Maybe do this in the ADT class
			  //engword = toupper(engword, loc);
			  //klinword = toupper(klinword, loc);
			  b->addNode(engword, klinword);
			  //b->print(b->Root());
		  
			  numLoops++;

			}
		
			cout <<"Current number of words in tree: " << b->getWordCount() << endl;
			cout <<"Current number of loops: " << numLoops << endl;
			//if(b->isEmpty() == true)
			//cout << "tree is empty";
			
		if (argc == 2)
		{
			cout << "Reading from a file:" << endl;
			b->print(b->Root());
		}

		
		delete b;
		myfile.close();

	}
	else cout << "Unable to open file" << endl; 
	
	if (argc == 1) //Assuming it starts from 1 and not 0
	{

		  cout << "Reading from cin:" << endl; 
		  string aWord;
		  //while(getline(cin, aWord)) 
		 // { // while (there is data)
		    // Translate aWord.
			  //if(b->search(aWord) == true)
			  //{
				  cout << aWord << b->Root()->getKlinWord() << endl;
				  //cout << aWord << b->printKlinWord() << endl;
			  //}
			  //else 
			  //{
				  cout << "Word not found" << endl;
			  //}

		 // }

	}
	

	
	return 0;
}







