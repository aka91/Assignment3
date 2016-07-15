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
#include <ctype.h>
#include <stdio.h>


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

	size_t pos = 0;
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
		string delimiter = ":";

			while (getline(myfile, line))
			{
				while((pos = line.find(delimiter)) != std::string::npos)
				{
					//////////Works////////////
					  engword = line.substr(0,pos);
					  line.erase(0, pos + delimiter.length());
					  klinword = line.substr(0,pos);
					//////////////////////////////
					

							
					  //line >> klinword;
					  //istringstream ss(':');
					  //ss >> engword;
					  //ss >> engword >> delimiter >> klinword;
					  //ss >> engword >> klinword; //Dont know if delimiter is necessary

					  //getline(ss, engword, ';');
					  //getline(ss, klinword);

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
					  
					  //std::cout << klinword << endl;
		  
					  numLoops++;
					  
				}
			}
			//std::cout << endl << endl << endl << endl << endl;
			std::cout <<"Current number of words in tree: " << b->getWordCount() << endl;
			std::cout <<"Current number of loops: " << numLoops << endl;
			//if(b->isEmpty() == true)
			//cout << "tree is empty";
		
		if (argc == 2)
		{
			std::cout << "Reading from a file:" << endl;
			//b->print(b->Root());
			
			////////Works when outside of if statement///////////
			std::cout << endl << endl << endl << endl << endl;
		
			b->print(b->Root());

			std::cout << endl << endl;
		}
		
		b->print(b->Root());
		/*
		if(b->search("wonder"))
		{
			std::cout << ": " << b->Root()->getKlinWord() << endl;
		}
		else
		{
			std::cout << "Word does not exist" << endl;
		}

		*/ 

		//std::cout << "win: " << b->Root()->getKlinWord() << endl;
		
		
		if (argv[2] != "display") //Assuming it starts from 1 and not 0
		{

		  std::cout << "Reading from cin:" << endl; 
		  string aWord;

		  while(getline(cin, aWord)) 
		  { // while (there is data)
		    // Translate aWord.
			  engword = aWord;
			  ////////Doesnt seem to work properly/////////
			  //////////Only works for the first time//////
			  if(b->search(engword))
				{
					std::cout << engword << ": " << b->Root()->getKlinWord() << endl;
					//b->Root()->setRight(NULL);
					//b->Root()->setLeft(NULL);
				}
			  else 
			  {
				  std::cout << "Word not found" << endl;
			  }

		  }

		}
		else if (argv[2] == "display") //Test this!!!!
		{
			b->print(b->Root());
			
			std::cout << endl << endl << endl << endl << endl;
		
			b->print(b->Root());

			std::cout << endl << endl;

		}

		myfile.close();

	}
	else std::cout << "Unable to open file" << endl; 
	/*
	if (argc == 1) //Assuming it starts from 1 and not 0
	{

		  std::cout << "Reading from cin:" << endl; 
		  string aWord;
		  while (getline(myfile, line))
		  {
				while((pos = line.find(delimiter)) != std::string::npos)
				{
					//////////Works////////////
					  engword = line.substr(0,pos);
					  line.erase(0, pos + delimiter.length());
					  klinword = line.substr(0,pos);
					//////////////////////////////

					if(b->search(aWord))
					{
						std::cout << aWord << ": " << b->Root()->getKlinWord() << endl;
					}
					else 
					{
						std::cout << "Word not found" << endl;
					}
				}

		  }

	}
	
	*/
	delete b;
	return 0;
}







