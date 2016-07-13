//  EKTApp.cpp
//  Assignment#3
//
//  Created by Alex Kim on 2016-07-15.
//  Copyright 2016 DEVELOPED BY SFU COMPUTER SCIENSE STUDENTS. All rights reserved.
//
// File:        EKTApp.cpp
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
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char *argv[])
{
 	//Populating the translator by opening the file and 
	char* filename = "dataFile.txt";
	string engword;
	string klinword;
	ifstream myfile (filename);

	BinarySearchTree b;
	BinarySearchTree c;

	if (myfile.is_open())
	{
		cout << "Reading from a file:" << endl; 
		string line;
		char delimiter(':');
		while (getline( myfile, line, delimiter ) )
		{
		  istringstream ss(line);
		  ss >> klinword >> engword;
		  
		  //cout << klinword << endl;
		  //locale loc;
	
		  b.insert(engword, klinword); //works
		 
		  b.display();

		  //Shouldn't do this when need to display
		  //Maybe do this in the ADT class
		  //engword = toupper(engword, loc);
		  //klinword = toupper(klinword, loc);

		 


		}

		cout <<"Current number of words in tree: " << b.getWordCount() << endl;
		if(b.isEmpty() == true)
		cout << "tree is empty";
		
		

		myfile.close();

	}
	else cout << "Unable to open file" << endl; 

	if (argc == 1) //Assuming it starts from 1 and not 0
	{

		  cout << "Reading from cin:" << endl; 
		  string aWord;
		  while(getline(cin, aWord)) // while (there is data)
		  {   
		    c.display(aWord);// Translate aWord.
		  }

	}



	return 0;
}






