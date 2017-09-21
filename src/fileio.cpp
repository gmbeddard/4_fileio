//============================================================================
// Name        : 3_File_IO.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

//global to this file
 const std::string MYFILE = "TestFile.txt";

void writeFile() {
	ofstream myOutputfile;
	myOutputfile.open(MYFILE.c_str());	//could open with  flags myfile.open(MYFILE, ios::out)
										//note the .c_str() call on MYFILE
	myOutputfile << "Writing this to a file.\n";

	//delicate, what if exception is thrown after file is opened
	//but before next line?
	//never close the file, resource leak, and some systems
	//limit number file handles open,
	myOutputfile.close();
}

void readFile(){
	ifstream myInputfile;
	myInputfile.open(MYFILE.c_str());
	myInputfile.open(MYFILE.c_str(), ios::trunc);	//could open with  flags myfile.open(MYFILE, ios::in)
												//note the .c_str() call on MYFILE
	//read and count the data
	std::string line;
	while (!myInputfile.eof()) {				//exits when reach end of file
		getline(myInputfile, line);				//gets a line up to '/n' char
		cout<<line;
	}

	//delicate, what if exception is thrown after file is opened
	//but before next line?
	//never close the file, resource leak, and some systems
	//limit number file handles open,
	myInputfile.close();
}


int main() {
	writeFile();
	readFile();
}



