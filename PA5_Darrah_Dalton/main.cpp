#include <iostream>
#include "String.h"
#include <fstream>

using namespace std;

const int MAX_STR_LEN = 20; 

void getFileName(char *ptr);

int main ()
{
	String s1, s2; 
	String array[10];
	String array2[10];
	String *arrayPointer;
	arrayPointer = array;
	String *arrayHome = arrayPointer;
	String *sTempPointer;
	sTempPointer = array2; 
	String *sTempHome = sTempPointer;

	ifstream fin;
	char *filePtr = new char[MAX_STR_LEN];
	char dummyChar[MAX_STR_LEN];
	char dummyChar2[MAX_STR_LEN];
	char *charPointer;
	char *charPointer2;
	char temp[MAX_STR_LEN];
	char *tempPointer; 
	tempPointer = temp; 
	char *tempHome = tempPointer;
	int increment;



	//filePtr = fileName; 
	getFileName(filePtr);

	//cout << filePtr << endl;

	fin.clear();
	fin.open(filePtr);

	if (fin.good()){

		//THIS SECTION TAKES IN ALL DATA AND STORES IT PROPERLY///
		fin >> dummyChar;
		fin >> dummyChar2;
		charPointer = dummyChar; 
		charPointer2 = dummyChar2;
		s1.initialize(charPointer);
		s2.initialize(charPointer2);

		s1.print();
		s1.concat(s2);
		s2.print();
		s1.print();

		for (increment = 0; increment < 10; increment++){
			fin >> temp;
			tempPointer = temp;
			(*arrayPointer).initialize(tempPointer);
			(*sTempPointer).initialize(tempPointer);
			tempPointer++; 
			arrayPointer++;
			sTempPointer++; 
		}
		tempPointer = tempHome;
		arrayPointer = arrayHome;
		sTempPointer = sTempHome;
	
		//////////////////////////////////////////////////////////
		/*
		//Concat with two seperate arrays ////////////////////////
		for (increment = 0; increment < 9; increment++){
			(*arrayPointer).concat(*sTempPointer);
			sTempPointer++;
			(*arrayPointer).print();
		}
		(*arrayPointer).print();
		sTempPointer = sTempHome;
		arrayPointer = arrayHome;
		
		//////////////////////////////////////////////////////////

		arrayPointer++;
		String *copyTemp;
		copyTemp = arrayPointer;

		(*copyTemp).print();
		(*arrayPointer).copy(*copyTemp);
		(*arrayPointer).print();
	*/

		
	s1.deallocate();
	s2.deallocate();
	}
	else {
		cout << "Your file was not found :(" << endl;
	}

	fin.close();

	delete [] filePtr;

	return 0;
}

void getFileName(char *ptr)
{

	cout << "Enter the file name now: " ;
	cin >> ptr; 
}