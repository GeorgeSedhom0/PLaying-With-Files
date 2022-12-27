// PLaying-With-Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
// this is a very very simple app for learning more about playing around with file using cpp, have fun

#include <iostream>	
#include <fstream>
#include <string>
using namespace std;

int main()
{
	// trying to print all the letter of the file each on a line with a number
	// first let's create a file and write some text in it
	ofstream file;
	file.open("text", ios::out);
	file << "Hello World";
	// tellp should return the number of characters in the file
	int pos = file.tellp();
	cout << "this is the current pos after writing: " << pos << endl;
	file.close();
	
	// now let's reopen this same file and read every letter in a line
	ifstream sameFileLOL;
	sameFileLOL.open("text", ios::in);
	char letters;
	cout << endl << "this is the content of the file letter each line: " << endl;
	
	while (!sameFileLOL.eof()) {
		sameFileLOL >> letters;

		// using tellg to get the position of the letter in the file
		int pos = sameFileLOL.tellg();
		
		// for some reason the eof function will allow the loop to run one extra
		// a work around is to check if the possition is more than 0
		
		if (pos > 0) {
			cout << letters << " - " << pos << endl;
		}
		
	}

	sameFileLOL.close();

	// let's try to make use of what we know so far
	// from the top of my head we can get the position on the line and number the lines of a document
	// will have text file created and input some lines first

	ofstream file2;
	file2.open("text2", ios::out);
	
	file2 << "Hello World this is a new world" << endl;
	file2 << "Hello World this is a new world" << endl;
	file2 << "Hello World this is a new world" << endl;
	file2 << "Hello World this is a new world" << endl;
	file2 << "Hello World this is a new world" << endl;
	
	file2.close();

	// now let's reopen this same file and read all lines but output them with a number
	ifstream sameFileLOL2;
	sameFileLOL2.open("text2", ios::in);
	
	string wholeFile;
	string line;

	cout << endl << "this is the content of the file line each line: " << endl;
	int lineNum = 1;

	while (!sameFileLOL2.eof()) {
		// which should the string line filled with the current first line
		getline(sameFileLOL2, line);

		// using tellg to get the position of the letter in the file
		int pos = sameFileLOL2.tellg();

		// for some reason the eof function will allow the loop to run one extra
		// a work around is to check if the possition is more than 0

		if (pos > 0) {
			cout << lineNum << " - " << line << endl;
			string strLineNum = ::to_string(lineNum);

			wholeFile += strLineNum + " - " + line + "\n";
			lineNum++;
		}

	}
	cout << "the whole file is: " << endl << wholeFile << endl;
	sameFileLOL2.close();

	// let's now open a new file and put these exact data in it

	ofstream newFile;
	newFile.open("Data", ios::out);

	newFile << "This file should have numbered lines" << endl;
	newFile << wholeFile;

	cout << "you can now open the folder and check if the data was copied after numberg";

	newFile.close();
}

