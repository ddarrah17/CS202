#include <iostream> 
#include "Agency.h"
#include <fstream>

using namespace std; 

const int MAX_STR_LEN = 30; 
const int CAR_COUNT = 15; 

Car::Car()
{
	
	make = new char[MAX_STR_LEN];
	model = new char[MAX_STR_LEN];
	year = 0; 
	price = 0.00; 
	available = 0; 

}

Car::Car(char *carmake, char *carmodel, int caryear, float carprice, bool caravailable)
{

	year = caryear; 
	price = carprice; 
	available = caravailable; 

	make = new char[MAX_STR_LEN];
	model = new char[MAX_STR_LEN];

	char *makeHome = make; 
	char *modelHome = model; 
	char *nullPointer = NULL;

	while(*carmake != '\0'){
		*make = *carmake;
		make++;
		carmake++; 
	}
	make = NULL;

	make = makeHome; 

	while(*carmodel != '\0'){
		*model = *carmodel; 
		model++;
		carmodel++; 
	}
	model = nullPointer;
	model = modelHome; 
}


Car::Car(const Car &cpyCar)
{

	year = cpyCar.year;
	price = cpyCar.price; 
	available = cpyCar.available;
	make = new char[MAX_STR_LEN];
	model = new char[MAX_STR_LEN];

	
	char *makeHome = make; 
	char *modelHome = model; 
	char *cpyCarPtr; 

	cpyCarPtr = cpyCar.make; 

	while (*cpyCarPtr != '\0'){
		*make = *cpyCarPtr;
		make++; 
		cpyCarPtr++; 
	}
	make = makeHome; 
	
	cpyCarPtr = cpyCar.model; 

	while (*cpyCarPtr != '\0'){
		*model = *cpyCarPtr; 
		model++;
		cpyCarPtr++; 
	}
	model = modelHome;  
}

Car::~Car()
{
	delete [] make; 
	delete [] model; 
}

void Car::copy(Car cpyCar)
{
	year = cpyCar.year;
	price = cpyCar.price; 
	available = cpyCar.available;
	make = new char[MAX_STR_LEN];
	model = new char[MAX_STR_LEN];

	
	char *makeHome = make; 
	char *modelHome = model; 
	char *cpyCarPtr; 

	cpyCarPtr = cpyCar.make; 

	while (*cpyCarPtr != '\0'){
		*make = *cpyCarPtr;
		make++; 
		cpyCarPtr++; 
	}
	make = makeHome; 
	
	cpyCarPtr = cpyCar.model; 

	while (*cpyCarPtr != '\0'){
		*model = *cpyCarPtr; 
		model++;
		cpyCarPtr++; 
	}
	model = modelHome;  
}

void Car::print() const
{
	cout << "Car Make: " << make << endl;
	cout << "Car Model: " << model << endl;
	cout << "Car Year: " << year << endl;
	cout << "Car Price: $ " << price << endl;
	if (available == 1){
		cout << "Car available: True" << endl;
	}
	else if (available == 0){
		cout << "Car available: False" << endl;
	}
	cout << endl;
}

char* Car::getMake() const
{
	return make; 
}

char* Car::getModel() const
{
	return model; 
}

int Car::getYear() const
{
	return year; 
}

float Car::getPrice() const
{
	return price; 
}

bool Car::getAvailable() const
{
	return available;
}

void Car::setMake(char *makeDum)
{
	char *makeHome = make; 
	
	while (*makeDum != '\0' || *make != '\0'){
		*make = *makeDum;
		make++; 
		makeDum++;
	}
	make = makeHome; 
	
}

void Car::setModel(char *modelDum)
{
	char *modelHome = model; 
	
	while (*modelDum != '\0' || *model != '\0'){
		*model = *modelDum;
		model++; 
		modelDum++;
	}
	model = modelHome; 
	
}

void Car::setYear(int yearDum)
{
	year = yearDum;
}

void Car::setPrice(float priceDum)
{
	price = priceDum;
}

void Car::setAvailable(bool availableDum)
{
	available = availableDum;
}

Agency::Agency()
{
	inventory = new Car[CAR_COUNT]; 
	name = new char[MAX_STR_LEN];
 	zipcode = new int[MAX_STR_LEN];
}

Agency::Agency(const Agency &agencyCpy)
{
	int increment; 
	cout << "Copy Constructor" << endl;
	name = new char[MAX_STR_LEN];
	zipcode = new int[5];
	inventory = new Car[CAR_COUNT];

	char *nameHome = name; 
	int *zipHome = zipcode; 
	Car *inventoryHome = inventory; 

	char *nameCpyPtr = agencyCpy.name; 

	while (*nameCpyPtr != '\0'){
		*name = *nameCpyPtr; 
		name++; 
		nameCpyPtr++;
	}
	*name = '\0';
	name = nameHome; 

	int *zipCpyPtr = agencyCpy.zipcode; 

	for(increment = 0; increment < 5; increment++){
		*zipcode = *zipCpyPtr;
		zipcode++; 
		zipCpyPtr++; 
	}
	zipcode = zipHome; 

	Car *inventoryCpyPtr = agencyCpy.inventory;

	for(increment = 0; increment < CAR_COUNT; increment++){
		*inventory = *inventoryCpyPtr; 
		inventory++; 
		inventoryCpyPtr++; 
	}
	inventory = inventoryHome; 
}

Agency::~Agency()
{
	delete [] inventory;
	delete [] name; 
	delete [] zipcode; 
}

void Agency::readInData(char *filePointer)
{	
	ifstream fin;
	int increment; 
	zipcode = new int[5]; 
	int *zipHome = zipcode;
	char temp; 

	//Dummy Varis for read in 
	int dummyYear; 
	float dummyPrice; 
	bool dummyAvail;
	char *dummyMake = new char[MAX_STR_LEN];
	char *dummyModel = new char[MAX_STR_LEN]; 

	//Home pointer for inventory
	Car *inventoryHome = inventory;

	fin.clear();
	fin.open(filePointer);

	if (fin.good()){

		cout << "file is open..." << endl;

		cout << "Reading in the Agency Name..." << endl;
		fin >> name;

		cout << "Reading in the Zipcode..." << endl << endl;

		//Read in white space
		fin.get(temp);
		
		for (increment = 0; increment < 5; increment++){
			 fin.get(temp);
			 temp = temp - '0';
			 (*zipcode) = temp; 
			 zipcode++;
		}
		zipcode = zipHome;

		//Create a loop to read in all the car data
		for (increment = 0; increment < CAR_COUNT; increment++){

			//Read in the car year
			fin >> dummyYear; 
			(*inventory).setYear(dummyYear);

			//Read in the car make
			fin >> dummyMake;
			(*inventory).setMake(dummyMake);

			//Read in the car model
			fin >> dummyModel;
			(*inventory).setModel(dummyModel);

			//Read in the car price
			fin >> dummyPrice; 
			(*inventory).setPrice(dummyPrice);

			//Read in the car availablilty 
			fin >> dummyAvail; 
			(*inventory).setAvailable(dummyAvail);

			inventory++; 
		}
			inventory = inventoryHome;

	}
	else 
		cout << "The file you have entered was not found..." << endl;

	fin.close();

}

void Agency::print() const
{
	int increment; 
	int *tempCode = zipcode; 
	int *tempHome = tempCode;

	//Home pointer for inventory
	Car *inventoryTemp = inventory;
	Car *tempHomeInv = inventoryTemp;

	cout << "Agency name: ";
	cout << name << endl;
	cout << "Zipcode: "; 
	for (increment = 0; increment < 5; increment++){
		cout << *tempCode;
		tempCode++;
	}
	cout << endl << endl;
	tempCode = tempHome;

	for (increment = 0; increment < CAR_COUNT; increment++){
		cout << "CAR DATA #" << increment + 1 << endl;
		cout << "============" << endl;
		(*inventoryTemp).print();	
		inventoryTemp++;
	}
	inventoryTemp = tempHomeInv; 

}

void Agency::printAvailableCars() const
{
	Car *inventoryTemp = inventory; 
	Car *inventoryHome = inventoryTemp;
	int increment; 

	cout << "-------------AVAILABLE CARS-------------" << endl << endl;
	for (increment = 0; increment < CAR_COUNT; increment++){
		if ((*inventoryTemp).getAvailable() == 1){

			(*inventoryTemp).print();
		}
		inventoryTemp++; 
	}

}

void Agency::findMostExpensive() const
{
	float mostExpensive = (*inventory).getPrice();
	float tempExp;
	Car *tempInventory = inventory; 
	Car *tempHome = tempInventory; 
	int increment, mostExpensiveIndex = 0; 

	//Moves pointer one up from slot 0 
	tempInventory++; 
	
	for (increment = 1; increment < CAR_COUNT; increment++){
		tempExp = (*tempInventory).getPrice();
		if (tempExp > mostExpensive){
			mostExpensive = tempExp;
			mostExpensiveIndex = increment; 
		}
		tempInventory++; 
	} 
	tempInventory = tempHome;

	for (increment = 0; increment < mostExpensiveIndex; increment++){
		tempInventory++; 
	}

	cout << "-------------MOST EXPENSIVE CAR-------------" << endl << endl; 
	cout << "The most expensive car in this Agency was the " << (*tempInventory).getMake() << " " << (*tempInventory).getModel() << "." << endl;
	cout << "With a price of:  $ " << (*tempInventory).getPrice() << endl << endl; 

}

float Agency::estimateCost(int carNumber, int numDays) const
{
	Car *tempInventory = inventory; 
	Car *tempHome = tempInventory; 
	float tempPrice, total; 
	int increment; 

	
	for (increment = 0; increment < carNumber - 1; increment++){
		tempInventory++; 
	}

	cout << "-------------PRINT ESTIMATION-------------" << endl << endl;
	cout << "The car you have selected to rent for " << numDays << " days is the " << (*tempInventory).getMake() << " " << (*tempInventory).getModel() << "." << endl;
	tempPrice = (*tempInventory).getPrice();
	total = tempPrice * numDays; 
	cout << "The total comes to: $ " << total << endl << endl;
	return total; 

}

void Agency::sortByMake()   // alphabetical
{

}

void Agency::sortByPrice()   // highest to lowest
{

}

void Agency::searchByMake(char *makeName) const
{

}