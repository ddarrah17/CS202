#include <iostream>
#include <fstream> 

using namespace std;

const int NUM_OF_NAMES = 10;
const int STR_LEN = 10;

void promptForFile(char fileArray[]);

void collectNames(char nameArray[][STR_LEN], char fileArray[]);

void printUnsortedArray(char nameArray[][STR_LEN]);

void printSortedArray(char nameArray[][STR_LEN]);

int stringCompare(char nameArray[][STR_LEN], int row);

void stringCopy(char nameArray[][STR_LEN], int row);

void bubbleSort(char nameArray[][STR_LEN]);

void writeToFile(char nameArray[][STR_LEN], char outputFileName[]);

void promptForFileOutput(char outputFileName[]);

int main()
{
	
	char inputFileName[STR_LEN];
	char outputFileName[STR_LEN];
	char namesList[NUM_OF_NAMES][STR_LEN];
	char tempArray[NUM_OF_NAMES][STR_LEN];

	promptForFile(inputFileName);

	collectNames(namesList, inputFileName);

	printUnsortedArray(namesList);
	
	bubbleSort(namesList);

	printSortedArray(namesList);

	promptForFileOutput(outputFileName);

	writeToFile(namesList, outputFileName);

	return 0;
}


void promptForFile(char fileArray[])
{
	
	cout << "Enter the name of your file you wish to sort : ";
	cin >> fileArray;


}

void collectNames(char nameArray[][STR_LEN], char fileArray[])
{
	ifstream fin;
	int increment;

	fin.clear();
	fin.open(fileArray);

	for (increment = 0; increment < NUM_OF_NAMES; increment++){
		fin >> nameArray[increment];
	}

	fin.close();
}

void printUnsortedArray(char nameArray[][STR_LEN])
{
	int increment;

	cout << endl;
	
	cout << "Unsorted Names" << endl << endl;
	cout << "==============" << endl << endl;

	for(increment = 0; increment < NUM_OF_NAMES; increment++){
		cout << nameArray[increment] << endl << endl;
	}
	
	cout << endl;
}

void printSortedArray(char nameArray[][STR_LEN])
{
	int increment;

	cout << "Sorted Names" << endl << endl;
	cout << "============" << endl << endl; 

	for(increment = 0; increment < NUM_OF_NAMES; increment++){
		cout << nameArray[increment] << endl << endl;
	}
	
	cout << endl;
}

int stringCompare(char nameArray[][STR_LEN], int row)
{
	int col;

	for(col = 0; col < STR_LEN; col++){
		if (nameArray[row][col] > nameArray[row+1][col]){
			return 1; 
		}
		if (nameArray[row][col] < nameArray[row+1][col]){
			return 0; 
		}
	}
	return 0; 
}

void stringCopy(char nameArray[][STR_LEN], int row)
{
	char tempArray[STR_LEN];
	int col;

	for(col = 0; col < STR_LEN; col++){
		tempArray[col] = nameArray[row][col];
		nameArray[row][col] = nameArray[row+1][col];
		nameArray[row+1][col] = tempArray[col];
	}
}

void bubbleSort(char nameArray[][STR_LEN])
{
	int swap;
	int row, col; 
	bool swapping = true;

	while(swapping != false){
	
		swapping = false;

		for(row = 0; row < NUM_OF_NAMES - 1; row++){
			for (col = 0; col < STR_LEN - 1; col++){
					swap = stringCompare(nameArray, row);
					if (swap == 1){
						stringCopy(nameArray, row);
						swapping = true;
					}
				}
			}
		}
	
}

void writeToFile(char nameArray[][STR_LEN], char outputFileName[])
{

	ofstream fout;
	int row, col;

	fout.clear();
	fout.open(outputFileName);

	for (row = 0; row < NUM_OF_NAMES; row++){
		for (col = 0; col < STR_LEN; col++){
			if (nameArray[row][col] == '\0'){
				break;
			}
			fout << nameArray[row][col];
		}
		fout << endl;
	}

	fout.close();

}


void promptForFileOutput(char outputFileName[])
{

	cout << "Enter the name of the file you wish to write the sorted names to: ";
	cin >> outputFileName;
}