#include <iostream>
#include "String.h"

using namespace std;


void String::initialize(char *str)
{
	
	int length = 0, increment;
	char *bufferHome;
	char *strHome;


	strHome = str;
	//Count how long the string is
	while (*str != '\0'){
		length++;
		str++;
	}

	str = strHome;

	//Assigns the length of the string to the private variable
	wordLength = length;
	//Assigns the buffer to a dynamic array of length's size
	buffer = new char [length + 1];

	//Sets bufferhome to the first place of buffer
	bufferHome = buffer;
	
	
	//Starts a for loop to increment through and make the buffer char in the class equal to the current str put into the function
	while (*str != '\0'){
		*buffer = *str;
		buffer++;
		str++;
	}
	
	//Buffer is returned to previous state after string manipulation
	buffer = bufferHome;
	str = strHome;

}

void String::deallocate()
{
	delete [] buffer;
	buffer = NULL;
}

void String::copy(const String &srcStr)
{
	int sourceLen;
	char *temp = srcStr.buffer;
	char *bufferHome = buffer;

	sourceLen = srcStr.wordLength;

	//THIS IF STATEMENT CHECKS IF THE WORDLENGTH IS NOT EQUAL TO THE SOURCE, IF ITS NOT
	//THE BUFFER POINTER IS DELETED AND REALLOCATED TO THE CORRECT SIZE OF SOURCE
	if (wordLength != sourceLen){
		wordLength = sourceLen; 
		delete [] buffer;
		buffer = new char [sourceLen + 1];
	}
	while (*temp != '\0'){
		*buffer = *temp;
		buffer++;
		temp++;
	}
	buffer = bufferHome;
}	

int String::length()
{
	return wordLength; //Returns the length of the string that the variable buffer is holding
}	

void String::concat(const String &srcStr)
{
	char *temp = srcStr.buffer;
	char *bufferHome = buffer;  
	char *tempbuffer = new char [wordLength + 1];
	char *tempHome = tempbuffer; 
	int increment; 

	wordLength = wordLength + srcStr.wordLength;
	
	
	while (*buffer != '\0'){
		*tempbuffer = *buffer;
		buffer++;
		tempbuffer++;
	}
	
	tempbuffer = tempHome;
	buffer = bufferHome;

	delete [] buffer;

	buffer = new char [wordLength + 1];

	bufferHome = buffer; 

	while(*tempbuffer != '\0'){
		*buffer = *tempbuffer;
		tempbuffer++;
		buffer++;
	}
	while(*temp != '\0'){
		*buffer = *temp;
		temp++;
		buffer++;
	}

	buffer = bufferHome;
}

int String::compare(const String &srcStr)
{
	char *temp; 
	temp = srcStr.buffer;
	char *bufferHome = buffer;

	while(*temp != '\0' && *buffer != '\0'){

		if (*temp > *buffer){
			buffer = bufferHome;
			cout << "ADT is alphabetically larger." << endl;
			return 1; 
		}
		if (*temp < *buffer){
			buffer = bufferHome;
			cout << "buffer is alphabetically larger." << endl;
			return -1; 
		}
		temp++;
		buffer++;
	}
	if (*temp == *buffer){
		buffer = bufferHome;
		cout << "They are alphabetically the same." << endl;
		return 0;
	}
	buffer = bufferHome;
	
}

void String::print()
{
	int increment; 
	char *bufferHome = buffer;
	for (increment = 0; increment < wordLength; increment++){
		cout << *buffer;
		buffer++; 
	}
	cout << endl;
	buffer = bufferHome;
}