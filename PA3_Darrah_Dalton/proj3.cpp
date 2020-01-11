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

//Struct for the Agency
struct Agency 
{
	char agencyName[MAX_STR_LEN];
	int zipcode[5];
	rentalCar inventory[5];
};

//Function: menuPrompt
//Purpose: prompts the user with a menu to select from
int menuPrompt();

//Function: getFilename
//Purpose: prompts the user to get the filename to get the data from
void getFilename(char *fileptr);


//Function: storeInfo
//Purpose: this takes all the data from the file given and stores it into a struct
void storeInfo(char *fileptr, Agency *aptr, char *zptr, int *iptr);

int main ()
{
	bool running = true; 
	int userSelection;
	char fileName[MAX_STR_LEN];
	char *fileptr = fileName;
	
	//Agency pointers
	Agency agencies[3];
	Agency *aptr;
	aptr = agencies;

	//Zip code pointers
	char zip[5];
	char *zptr;
	zptr = zip;

	//Inventory pointers
	int inventory[5];
	int *iptr;
	iptr = inventory;

	//Prompt user for the file name with the data for the cars 
	getFilename(fileptr);

	storeInfo(fileptr, aptr, zptr, iptr);


	while(running != false){
		
		//Opens menu for user to make selection for the data
		userSelection = menuPrompt();

		//First selection shows all data for all cars
		if(userSelection == 1){
		
		}
		//Second option estimates the cost of rental
		if(userSelection == 2){

		}
		//Thrid option finds the most expensive car in the file
		if(userSelection == 3){

		}
		//Fourth option prints out only the available cars in file
		if(userSelection == 4){

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

void getFilename(char *ptr)
{

	cout << "Enter the file name to retrieve the data from: " ;
	cin >> ptr;

}

void storeInfo(char *fileptr, Agency *aptr, char *zptr, int *iptr)
{
	ifstream fin;
	int increment;
	int pointerCount;
	

	fin.clear();
	fin.open(fileptr);
	//while(pointerCount != 4){

	fin >> (*aptr).agencyName;
	
	cout << (*aptr).agencyName << " " ;

	for(increment = 0; increment < 5; increment++){
	fin >> *zptr;
	cout << *zptr - '0';
	}

	fin >> (*iptr).carYear;

	cout << (*iptr).carYear; 
	
	//pointerCount++;

	cout << endl << endl;
	//}
}


