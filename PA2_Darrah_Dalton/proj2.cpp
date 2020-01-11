#include <iostream>
#include <fstream>

using namespace std;

const int MAX_STR_LEN = 20; 
const int NUM_CARS = 10;

//Struct for the rental car
struct rentalCar
{
	char carMake[MAX_STR_LEN];
	char carModel[MAX_STR_LEN];
	int carYear;
	float carPrice;
	bool carAvailable;
};

//Function: menuPrompt
//Purpose: prompts the user with a menu to select from
int menuPrompt();

//Function: getFilename
//Purpose: prompts the user to get the filename to get the data from
void getFilename(char fileName[MAX_STR_LEN]);

//Function: storeInfo
//Purpose: this takes all the data from the file given and stores it into a struct
void storeInfo(char fileName[MAX_STR_LEN], rentalCar a[NUM_CARS]);

//Function: optionOne
//Purpose: this is option one in the menu
void optionOne(rentalCar a[NUM_CARS]);

//Function: promptRentalChoice
//Purpose: this prompts the user to make a selection on which car they would like
void promptRentalChoice(int &carChoice, int &numDays);

//Function: estimationTotal
//Purpose: uses the car that user choice and estimates the amount it would cost rent for x amount of days
void estimationTotal(int &carChoice, int &numDays, float &rentTotal, rentalCar a[NUM_CARS]);

//Function: printEstimation 
//Purpose: this takes the estimation and prints it
void printEstimation(int &carChoice, int &numDays, float &rentTotal, rentalCar a[NUM_CARS]);

//Function: findMostExpensive
//Purpose: finds the most expensive car in the list 
void findMostExpensive(rentalCar a[NUM_CARS], int &highestCarNum);

//Function: printMostExpensive
//Purpose: prints the most expensive car
void printMostExpensive(int &highestCarNum, rentalCar a[NUM_CARS]);

//Function: printAvailableCars
//Purpose: prints only cars that are available
void printAvailableCars(rentalCar a[NUM_CARS]);

int main ()
{
	bool running = true; 
	int userSelection;
	char fileName[MAX_STR_LEN];
	int increment, highestCarNum;
	int carChoice, numDays;
	float rentTotal;

	rentalCar array[NUM_CARS];

	//Prompt user for the file name with the data for the cars 
	getFilename(fileName);

	storeInfo(fileName, array);

	while(running != false){
		
		//Opens menu for user to make selection for the data
		userSelection = menuPrompt();

		//First selection shows all data for all cars
		if(userSelection == 1){

			optionOne(array);

		}
		//Second option estimates the cost of rental
		if(userSelection == 2){

			promptRentalChoice(carChoice, numDays);

			estimationTotal(carChoice, numDays, rentTotal, array);

			printEstimation(carChoice, numDays, rentTotal, array);

		}
		//Thrid option finds the most expensive car in the file
		if(userSelection == 3){

			findMostExpensive(array, highestCarNum);

			printMostExpensive(highestCarNum, array);

		}
		//Fourth option prints out only the available cars in file
		if(userSelection == 4){

			printAvailableCars(array);

		}
		//Fifth option exits the user from the program
		if(userSelection == 5){
			running = false;
			break;
		}
	}
	return 0;
}

int menuPrompt()
{
	int userSelection;

	cout << "1. List all car data." << endl;
	cout << "2. Estimate car rental price." << endl;
	cout << "3. List most expensive car." << endl;
	cout << "4. List available cars only." << endl;
	cout << "5. End the program." << endl << endl;

	cout << "Enter your Selection: ";
	cin >> userSelection;

	cout << endl;

	switch (userSelection){

		case 1:
			return 1;
			break;

		case 2:
			return 2;
			break;

		case 3: 
			return 3; 
			break;

		case 4: 
			return 4;
			break;

		case 5: 
			return 5;
			break;

		default:
			cout << "That is not a possible selection, please try another." << endl;

	}
	return 0;
}

void getFilename(char fileName[MAX_STR_LEN])
{

	cout << "Enter the file name to retrieve the data from: " ;
	cin >> fileName;
}

void storeInfo(char fileName[MAX_STR_LEN], rentalCar a[NUM_CARS])
{
	ifstream fin;
	int increment;

	fin.clear();
	fin.open(fileName);

	for(increment = 0; increment < 10; increment++){
		fin >> a[increment].carYear;
		fin >> a[increment].carMake;
		fin >> a[increment].carModel;
		fin >> a[increment].carPrice;
		fin >> a[increment].carAvailable;
	}

}

void optionOne(rentalCar array[NUM_CARS])
{
	int increment;

	cout << "Here is every cars information: " << endl << endl;

	for(increment = 0; increment < NUM_CARS; increment++){
			cout << array[increment].carYear << " ";
			cout << array[increment].carMake << " ";
			cout << array[increment].carModel << " ";
			cout << array[increment].carPrice << " ";
			cout << array[increment].carAvailable << endl;
			}

			cout << endl;
}

void promptRentalChoice(int &carChoice, int &numDays)
{
	cout << "Enter the number corresponding to the car you wish to see an estimate for: " ;
	cin >> carChoice;

	cout << "Enter the number of days you'd wish to rent the vehicle for: " ;
	cin >> numDays;

}

void estimationTotal(int &carChoice, int &numDays, float &rentTotal, rentalCar a[NUM_CARS])
{
	float carPrice;

	carPrice = a[carChoice - 1].carPrice;

	rentTotal = carPrice * numDays;
}

void printEstimation(int &carChoice, int &numDays, float &rentTotal, rentalCar a[NUM_CARS])
{
	cout << "Your choice was " << carChoice << ", which correspondes to the " << a[carChoice - 1].carYear << " " << a[carChoice - 1].carMake << " " << a[carChoice -1].carModel << endl;
	cout << "The total cost to rent the car for " << numDays << " day(s) is " << rentTotal << endl;
}

void findMostExpensive(rentalCar a[NUM_CARS], int &highestCarNum)
{
	int increment;
	float highest = a[0].carPrice; 

	for(increment = 1; increment < NUM_CARS; increment++){
		if (a[0].carPrice < a[increment].carPrice){
			highest = a[increment].carPrice;
			highestCarNum = increment;
		}
	}
}

void printMostExpensive(int &highestCarNum, rentalCar a[NUM_CARS])
{
	cout << "The most expensive car to rent in this list is the " << a[highestCarNum].carYear << " " << a[highestCarNum].carMake << " " << a[highestCarNum].carModel << endl << endl;
}


void printAvailableCars(rentalCar array[NUM_CARS])
{
	int increment;

	cout << "These are the available cars from the list: " << endl;

	for(increment = 0; increment < NUM_CARS; increment++){
		if(array[increment].carAvailable == 1){
			cout << array[increment].carYear << " ";
			cout << array[increment].carMake << " ";
			cout << array[increment].carModel << " ";
			cout << array[increment].carPrice << endl;
		}
	}
	cout << endl;
}


