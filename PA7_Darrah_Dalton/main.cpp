#include <iostream> 
#include <fstream> 
#include "Project7.h"

using namespace std;


int main()
{
	Polynomial temp;
	int NumofPolys;
	int scalar, solveNum, answer; 
	Polynomial *polynomialArray;
	ifstream fin; 
	bool Equal = true, notEqual = true; 
	char filename[20];

	cout << "Enter your filename here: " ;
	cin >> filename;

	fin.open(filename);

if (fin.good()){	

	fin >> NumofPolys;

	polynomialArray = new Polynomial[NumofPolys];	

	cout << "***************************************" << endl;
	cout << "*        READING IN THE FILE...       *" << endl;
	cout << "***************************************" << endl << endl << endl;

	cout << "***************************************" << endl;
	cout << "*     PRINTING THE FILE CONTENTS      *" << endl;
	cout << "***************************************" << endl << endl;

	for(int i = 0; i < NumofPolys; i++){
		fin >> polynomialArray[i];
		cout << "Polynomial " << i+1 << " is : ";
		cout << polynomialArray[i] << endl;
	}

fin.close();
}

	cout << "***************************************" << endl;
	cout << "*     TESTING THE EQUALS OPERATOR     *" << endl;
	cout << "***************************************" << endl << endl;

	cout << "We tested Polynomial 1 & 2" << endl;
	Equal = (polynomialArray[0] == polynomialArray[1]);

	if (Equal == 1){
		cout << "This is True as the Polynomials are equal." << endl << endl;
	}
	else if (Equal == 0){
		cout << "This is False as the Polynomials are not equal." << endl << endl;
	}

	cout << "***************************************" << endl;
	cout << "*   TESTING THE NOT EQUAL OPERATOR    *" << endl;
	cout << "***************************************" << endl << endl;

	cout << "We tested Polynomial 1 & 2" << endl;
	notEqual = (polynomialArray[0] != polynomialArray[1]);

	if (notEqual == 1){
		cout << "This is True as the Polynomials are not equal." << endl << endl;
	}
	else if (notEqual == 0){
		cout << "This is False as the Polynomials are equal." << endl << endl;
	}


	cout << "***************************************" << endl;
	cout << "* TESTING THE MULTIPLICATION OPERATOR *" << endl;
	cout << "***************************************" << endl << endl;

	cout << "Polynomial 1 is: " << polynomialArray[0] << endl;
	cout << "Polynomial 2 is: " << polynomialArray[1] << endl;
	cout << "The multiplied polynomials are equal to: " << (polynomialArray[0] * polynomialArray[1]) << endl;

	cout << "***************************************" << endl;
	cout << "*     TESTING THE SCALAR OPERATOR     *" << endl;
	cout << "***************************************" << endl << endl;

	cout << "Enter the scalar you wish to multiply the Polynomial by: " ;
	cin >> scalar; 

	cout << "The Polynomial being multiplied is: " << polynomialArray[0] << endl;
	temp = (polynomialArray[0] * scalar);
	cout << "After multiplying by the scalar, the polynomial is equal to: " << temp << endl;

	cout << "***************************************" << endl;
	cout << "*    TESTING THE ADDITION OPERATOR    *" << endl;
	cout << "***************************************" << endl << endl;

	cout << "Polynomial 1 is: " << polynomialArray[0] << endl;
	cout << "Polynomial 2 is: " << polynomialArray[1] << endl;
	cout << "The added polynomials are equal to: " << (polynomialArray[0] + polynomialArray[1]) << endl;

	cout << "***************************************" << endl;
	cout << "*   TESTING THE SUBTRACTION OPERATOR  *" << endl;
	cout << "***************************************" << endl << endl;

	cout << "Polynomial 1 is: " << polynomialArray[0] << endl;
	cout << "Polynomial 2 is: " << polynomialArray[1] << endl;
	cout << "The subtracted polynomials are equal to: " << (polynomialArray[0] - polynomialArray[1]) << endl;

	cout << "***************************************" << endl;
	cout << "*      TESTING THE SOLVE FUNCTION     *" << endl;
	cout << "***************************************" << endl << endl;

	cout << "Enter the number you'd like to evaluate the polynomial at: ";
	cin >> solveNum;

	cout << "We are evaluating " << polynomialArray[0] << "We are making x = " << solveNum << endl;
	answer = polynomialArray[0].solve(solveNum);
	cout << "The answer is: " << answer << endl; 

	return 0; 
}