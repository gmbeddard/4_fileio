//============================================================================
// Name        : 3_File_IO.cpp
// Author      : gmbeddard
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

//global to this file
 const std::string MYFILE = "TestFile.txt"; //constant MYFILE should always be capitalized
 const int 	SUCCESS				= 0;
 const int 	COULD_NOT_OPEN_FILE = -1;

int writeFile() {
	ofstream myOutputfile;
	myOutputfile.open(MYFILE.c_str());	//could open with  flags myfile.open(MYFILE, ios::out)
										//note the .c_str() call on MYFILE
	if (!myOutputfile.is_open())
			return COULD_NOT_OPEN_FILE;

	myOutputfile << "Data for a file.\n";

	//delicate, what if exception is thrown after file is opened
	//but before next line?
	//never close the file, resource leak, and some systems
	//limit number file handles open,
	myOutputfile.close();
	return SUCCESS;
}

int readFile(){
	ifstream myInputfile;
	myInputfile.open(MYFILE.c_str());	//could open with  flags myfile.open(MYFILE, ios::in)
												//note the .c_str() call on MYFILE
	if (!myInputfile.is_open())
			return COULD_NOT_OPEN_FILE;

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
	return SUCCESS;
}


int main() {
	cout << "Writing to a file"<<endl;
	int res = writeFile();
	if(res == COULD_NOT_OPEN_FILE)
		cout << "Writing to a file"<<endl;


	cout << "Reading following string from a file"<<endl;
	res = readFile();
	if(res == COULD_NOT_OPEN_FILE)
		cout << "Writing to a file"<<endl;

}



