#include <iostream> 
#include "Agency.h"

using namespace std; 

const int MAX_STR_LEN = 20;

void menuTitle();
int menuOption();

int main()
{
	Agency a1;
	bool stillRunning = true; 
	int choice, carNum, dayNum; 
	char *filePtr = new char[MAX_STR_LEN];
	char *makeSearch = new char[MAX_STR_LEN];

	menuTitle();

	while (stillRunning != false){

		choice = menuOption(); 

		switch (choice){

			case 1: 
				cout << "Enter your file name here: " ;
				cin >> filePtr; 
				a1.readInData(filePtr);
				break; 
			case 2: 
				a1.print();
				break; 
			case 3:
				a1.printAvailableCars();
				break; 
			case 4: 
				a1.findMostExpensive();
				break; 
			case 5: 
				cout << "Enter the number for the car you wish to rent (1-15): " ;
				cin >> carNum; 
				cout << endl;
				cout << "Enter the amount of days you want to rent this car for: ";
				cin >> dayNum; 
				cout << endl; 
				a1.estimateCost(carNum, dayNum);
				break;
			case 6:
				a1.sortByMake();
				break; 
			case 7: 
				a1.sortByPrice();
				break; 
			case 8: 
				cout << "Enter the make you want to search for: ";
				cin >> makeSearch; 
				cout << endl;
				a1.searchByMake(makeSearch);
				break; 
			case 9: 
				stillRunning = false; 
				break; 
			default: 
				cout << "Not a valid choice, please try again.." << endl;
				break;

		}
	}
	return 0; 
}


void menuTitle()
{
	cout << "*************AGENCY & CAR CLASS MENU*************" << endl;
	cout << "=================================================" << endl;
}

int menuOption()
{
	int choice; 

	cout << "1. Read in file data." << endl << endl;
	cout << "2. Print agency data." << endl << endl;
	cout << "3. Print available cars." << endl << endl;
	cout << "4. Find most expensive." << endl << endl;
	cout << "5. Estimate a cost." << endl << endl;
	cout << "6. Sort by make." << endl << endl;
	cout << "7. Sort by price." << endl << endl;
	cout << "8. Search by make." << endl << endl;
	cout << "9. Exit the program." << endl << endl;

	cout << "Enter your choice here: ";
	cin >> choice; 

	cout << endl << endl;

	return choice; 
}