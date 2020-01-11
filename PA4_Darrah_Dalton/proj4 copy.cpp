#include <iostream>
#include <fstream> 

using namespace std;

const int MAX_STR_LEN = 20;

struct Pieces
{
	char *word;
	int jump;
};

void storeInput(char *fileName, int *wordCount, int *keyCount, Pieces *pointer, int *keyPtr);

void promptForFilename(char *fileName);

int main()
{
	int i;

	//Amount of words declared and pointer for cipher array size
	int* wordCountPtr = NULL;
	int wordCount = 10;
	wordCountPtr = &wordCount;
	
	//Amount of keys declated and pointer for key array
	int* keyCountPtr = NULL;
	int keyCount = 10;
	keyCountPtr = &keyCount;
	
	//File Name Declaration and pointer
	char fileName[MAX_STR_LEN] = "Project4Data.txt";
	char* filePtr = fileName;
	
	//Array for the cipher dynamically allocated
	Pieces *pPtr = NULL;
	pPtr = new Pieces[wordCount];
	if (pPtr == nullptr){
		cout << "The memory could not be allocated." << endl;
	}

	//Array for the Keys dynamically allocated
	int *keyPtr = NULL;
	keyPtr = new int[keyCount];
	if (keyPtr == nullptr){
		cout << "The memory could not be allocated." << endl;
	}

	//Prompts the user to enter the name of their file
	//promptForFilename(filePtr);


	//Stores the information in the correct place
	storeInput(filePtr, wordCountPtr, keyCountPtr, pPtr, keyPtr);

	cout << wordCount << endl << keyCount << endl;


	cout << *(*(pPtr)).word;
	

	delete [] pPtr;
	delete [] keyPtr;

	pPtr = NULL;
	keyPtr = NULL;

	return 0;
}

void storeInput(char *fileName, int *wordCount, int *keyCount, Pieces *pointer, int *keyPtr)
{
	ifstream fin;
	int increment;
	int numWords;
	int numKeys;

	
	fin.clear();
	fin.open(fileName);

	if(fin.good()){

	fin >> *wordCount;
	fin >> *keyCount;

	wordCount = &numWords;
	keyCount = &numKeys;

	for(increment = 0; increment < numWords; increment++){
		fin >> (*(pointer + increment)).word;
		fin >> (*(pointer + increment)).jump;
	}
	for (increment = 0; increment < numKeys; increment++){
		fin >> (*(keyPtr + increment));
	}

	}	
	else 
		cout << "The file you entered can't be found." << endl;


}

void promptForFilename(char *fileName)
{
	cout << "Please enter the name of the file you wish to decipher: " << endl;
	cout << "Name of file: " ;
	cin >> fileName;
}