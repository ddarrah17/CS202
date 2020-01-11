#include <iostream>
#include <fstream> 

using namespace std;

const int MAX_STR_LEN = 50;


struct Pieces
{
	char *word;
	int jump;
};

void wordAndKeyNum(int *wordCountPtr, int *keyCountPtr, ifstream &fin);

void promptForFilename(char *filePtr);

void readInCipher(Pieces *pPtr, int *keyPtr, ifstream &fin, int wordCount, int keyCount);

int strLen(char *string);

void strCpy(char *stringDest, char *stringSource);

void decodeMessage(Pieces *pPtr, int *keyPtr, char *decodePtr, int wordCount, int keyCount);

void strConcat(char *stringDest, char *stringSource);

int main()
{

	ifstream fin;
	int i;

	//File Name Declaration and pointer
	char fileName[MAX_STR_LEN] = "Project4Data.txt";
	char *filePtr = fileName;

	//Amount of words declared and pointer for cipher array size
	int *wordCountPtr;
	int wordCount = 10;
	wordCountPtr = &wordCount;
	
	//Amount of keys declated and pointer for key array
	int *keyCountPtr;
	int keyCount = 10;
	keyCountPtr = &keyCount;

	//Declares the char array that we will use for holding the decryption
	char *decodePtr;
	char *decodeHome;
	decodePtr = new char[50];
	decodeHome = decodePtr;

	//Prompts the user to enter the name of their file
	promptForFilename(filePtr);


	fin.clear();
	fin.open(filePtr);

	if (fin.good()){

	wordAndKeyNum(wordCountPtr, keyCountPtr, fin);


	//Array for the cipher dynamically allocated
	Pieces *pPtr;
	Pieces *homePieces;
	pPtr = new Pieces[wordCount];
	homePieces = pPtr;

	//Array for the Keys dynamically allocated
	int *keyPtr;
	int *homeKey;
	keyPtr = new int[keyCount];
	homeKey = keyPtr;

	readInCipher(pPtr, keyPtr, fin, wordCount, keyCount);

	pPtr = homePieces;
	keyPtr = homeKey;

	decodeMessage(pPtr, keyPtr, decodePtr, wordCount, keyCount);
   	decodePtr = decodeHome;
   	
	cout << "Your decoded message is: " << endl;
   	cout << decodePtr << endl;

	for (i = 0; i < wordCount; i++){
		delete [] (*pPtr).word;
		pPtr++;
	}
  
	delete [] keyPtr;
	keyPtr = NULL;
	delete [] decodePtr;
	decodePtr = NULL;
	pPtr = NULL;

	fin.close();

	}
	else 

		cout << "Your file was not found." << endl;

	return 0;
}

void wordAndKeyNum(int *wordCountPtr, int *keyCountPtr, ifstream &fin)
{

	fin >> *wordCountPtr;
	fin >> *keyCountPtr;

}


void promptForFilename(char *filePtr)
{
	cout << "Please enter the name of the file you wish to decipher: " << endl;
	cout << "Name of file: " ;
	cin >> filePtr;
}


void readInCipher(Pieces *pPtr, int *keyPtr, ifstream &fin, int wordCount, int keyCount)
{

	int index, wordLen;
	int *tempKey = NULL;
	char *dummychar = new char[20];
	int dummyint;

	for(index = 0; index < wordCount; index++){
		fin >> dummychar >> dummyint;
		wordLen = strLen(dummychar);
		(*pPtr).word = new char[wordLen];
		strCpy((*pPtr).word, dummychar);
		(*pPtr).jump = dummyint;
		pPtr++;

      
	}

	tempKey = keyPtr;

	for(index = 0; index < keyCount; index++){
		fin >> (*keyPtr);
		keyPtr++;
	}

	keyPtr = tempKey;

	delete [] dummychar;
	dummychar = NULL;
}

int strLen(char *string)
{
	int len;
	while (*string != '\0'){
		string++;
		len++;
	}
	return len;
}

void strCpy(char *stringDest, char *stringSource)
{
	while (*stringSource != '\0'){
		(*stringDest) = (*stringSource);
		*stringDest++;
		*stringSource++;
	}
}

void decodeMessage(Pieces *pPtr, int *keyPtr, char *decodePtr, int wordCount, int keyCount)
{
	int keyIndex;
	int key, jumpKey, temp;
	Pieces *homePiece = NULL;
	int *homeKey = NULL;
  	int total;
	char *spacePointer;
	char space[] = " ";
	spacePointer = space;

	homePiece = pPtr;
	homeKey = keyPtr;

   for (keyIndex = 0; keyIndex < keyCount; keyIndex++){
       
   //Sets an int variable to the amount that the keyPtr is currently on 
      key = (*keyPtr);
     
   //Adds the int amount to the pPtr to tell the pointer to look at the correct word for the key
      pPtr += key;
     
   jumpKey = (*pPtr).jump;
     
   total = jumpKey + key;
   
   if (total >= wordCount){
   temp = (wordCount + 1) - key;
   temp = temp - jumpKey;
   pPtr = homePiece;
   }

   
   
while (jumpKey != 0){
      
   pPtr += jumpKey;
   jumpKey = (*pPtr).jump;
   if ((*pPtr).jump == 0){
   break;
   }   
   }
   

   

   //Once checked and found the first value with a 0 jump value, copy this into the decode string
   strConcat(decodePtr, spacePointer);
   strConcat(decodePtr, (*pPtr).word);

   //After the word is found set the pPtr back to its home position to begin again from next key.
   pPtr = homePiece;             
   keyPtr++;
   
   }
	
}

void strConcat(char *stringDest, char *stringSource)
{
   while(*stringDest != '\0'){
    *stringDest++ ;
  }

  while(*stringSource != '\0'){
    *stringDest++ = *stringSource++ ;
  }
 *stringDest = '\0';
}
