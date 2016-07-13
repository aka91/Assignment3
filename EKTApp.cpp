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

// Include all header files here

using namespace std;

int main(int argc, char *argv[])
{
 	//Populating the translator by opening the file and 
	char* filename = "dataFile.txt";
	ifstream myfile (filename);
	if (myfile.is_open())
	{
		cout << "Reading from a file:" << endl; 
		string line;
		while ( getline (myfile,line) )
		{
		  cout << line << '\n';
		  istringstream ss(line);

		  string engword;
		  string klinword;

		  ss >> engword >> klinword;
		  cout << engword << klinword << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file"; 

	if (argc == 1) //Assuming it starts from 1 and not 0
	{

		  cout << "Reading from cin:" << endl; 
		  while(getline(cin, aWord)) {   // while (there is data)
		    // Translate aWord.
		  }

	}



	return 0;
}








