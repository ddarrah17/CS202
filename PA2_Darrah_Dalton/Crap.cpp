#include <iostream>

using namespace std; 

const int MAX_STR_LEN = 50;

void RemoveSpaces(char string[MAX_STR_LEN]);

int main()
{
	char string[MAX_STR_LEN];
	int i;
	cout << "Enter the string you want to take spaces from: " << endl;
	for (i = 0; i < MAX_STR_LEN; i++){
	cin >> string[i];
	}

	RemoveSpaces(string);

	cout << endl;
	cout << string << endl;

	return 0;
}

void RemoveSpaces(char string[MAX_STR_LEN])
{
	int i;

	for(i = 0; i < MAX_STR_LEN; i++){
		if(string[i] == '\0'){
			string[i] = '.';
		}
	}

}