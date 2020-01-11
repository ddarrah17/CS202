#include <iostream> 
#include "Agency.h"

using namespace std; 

const int CAR_NUMBER = 4; 
const int RENTAL_DAYS = 12;
int main()
{
	Agency a1; 

	char *filePointer = new char[20];

	filePointer = "Project_6_Data.txt";

	Car c1("Honda", "Civic", 2009, 112.56, 1);
	Car c2;

	// c1.print();
	// c2.print();
	// c2.copy(c1);
	// Car c3(c2);
	// c3.print();
	// cout << "AFTER COPY" << endl << endl;
	// c2.print();
	a1.readInData(filePointer);
	//a1.print();
	// a1.print();
	a1.printAvailableCars();
	a1.findMostExpensive();
	a1.estimateCost(CAR_NUMBER, RENTAL_DAYS);
	// Agency a2(a1);
	// a2.print();
	// //a1.print();
	// a1.estimateCost(5, 10);





	return 0; 
}