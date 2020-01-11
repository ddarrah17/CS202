#include <iostream>
#include "Project7.h"

using namespace std; 


Polynomial::Polynomial()
{
	maxDegree = 3; 
	polyArray = new int[maxDegree + 1];
}

Polynomial::Polynomial(int deg, int *arrayPtr)
{

	int i; 
	maxDegree = deg; 
	polyArray = new int[maxDegree + 1];

	for (i = 0; i < maxDegree + 1; i++){
	polyArray[i] = arrayPtr[i];
	}

}

Polynomial::Polynomial(const Polynomial& P1)
{
	
	maxDegree = P1.maxDegree;
	polyArray = new int[maxDegree + 1];
	for (int i = 0; i < maxDegree + 1; i++){
	polyArray[i] = P1.polyArray[i];
	}

}

Polynomial::~Polynomial()
{
	int i;
	
	for (i = 0; i < maxDegree + 1; i++){
		polyArray[i] = 0;
	}
	maxDegree = 0; 
}	

int Polynomial::solve(int eval) const
{
	int total = 1;
	int finTotal = 0; 
	int i, j; 
	int degreeCount = maxDegree; 

	for (i = 0; i < maxDegree+1; i++){
		for (j = 1; j < degreeCount+1; j++){
			total = total * eval;
		}

		total = total * polyArray[i];
		finTotal += total; 
		total = 1; 
		degreeCount--;
	}
	return finTotal; 

}

Polynomial& Polynomial::operator=(const Polynomial& P1)
{
	maxDegree = P1.maxDegree; 
	for (int i = 0; i < maxDegree+1; i++){
		polyArray[i] = P1.polyArray[i];
	}
}

bool Polynomial::operator==(const Polynomial& P1)
{
	if (maxDegree != P1.maxDegree){
		return false; 
	}
	for (int i = 0; i < maxDegree+1; i++){
		if (polyArray[i] != P1.polyArray[i]){
			return false;
		}
	}

	return true;

}

bool Polynomial::operator!=(const Polynomial& P1)
{
	if (maxDegree != P1.maxDegree){
		return true; 
	}
	for (int i = 0; i < maxDegree+1; i++){
		if (polyArray[i] != P1.polyArray[i]){
			return true;
		}
	}

	return false;
}

Polynomial Polynomial::operator*(const Polynomial& P1)
{
	Polynomial temp;
	int i, j;  

	int subtotal = (maxDegree + P1.maxDegree);
	temp.maxDegree = subtotal; 
	temp.polyArray = new int[subtotal + 1];

	for (i = 0; i < subtotal + 1; i++){
		temp.polyArray[i] = 0;
	}
	for (i = 0; i < subtotal; i++){
		for (j = 0; j < P1.maxDegree + 1; j++){
			temp.polyArray[i + j] += polyArray[i] * P1.polyArray[j];
		}
	}
	return temp;
}

Polynomial Polynomial::operator*(const int scalar)
{
	Polynomial temp; 
	int tempTotal = 0;
	int i, j; 
	int degreeCount = maxDegree; 
	temp.maxDegree = maxDegree; 

	for (i = 0; i < maxDegree+1; i++){
		//for (j = 0; j < degreeCount+1; j++){
			tempTotal = polyArray[i] * scalar;
		//}
		temp.polyArray[i] = tempTotal; 
		degreeCount--;
	}

	return temp;

}

Polynomial Polynomial::operator+(const Polynomial&P1)
{
	Polynomial temp; 
	int Min, Max; 
	int degreeCount1, degreeCount2; 
	int i = 0, j = 0;

	if (maxDegree > P1.maxDegree){
		Max = maxDegree;
		Min = P1.maxDegree;
	}
	else if (maxDegree < P1.maxDegree){
		Max = P1.maxDegree;
		Min = maxDegree;
	}
	else if (maxDegree == P1.maxDegree){
		Max = maxDegree; 
		Min = P1.maxDegree; 
	}

	degreeCount1 = Max; 
	degreeCount2 = Min; 

	temp.maxDegree = Max; 
	temp.polyArray = new int[Max];

	while (degreeCount1 != -1 || degreeCount2 != -1){
	if (Max == maxDegree && Min == P1.maxDegree){
		if (degreeCount1 == degreeCount2){
			temp.polyArray[i] = polyArray[i] + P1.polyArray[j];
			i++; 
			j++;
			degreeCount1--;
			degreeCount2--;

		}
		else if (degreeCount1 > degreeCount2){
			temp.polyArray[i] = polyArray[i];
			i++;
			degreeCount1--;
			
		}
		else if (degreeCount2 > degreeCount1){
			temp.polyArray[i] = P1.polyArray[j];
			i++;
			j++;
			degreeCount2--;
			
			}
		}
	else if (Max == P1.maxDegree && Min == maxDegree){
		if (degreeCount1 == degreeCount2){
			temp.polyArray[i] = P1.polyArray[i] + polyArray[j];
			i++; 
			j++;
			degreeCount1--;
			degreeCount2--;

		}
		else if (degreeCount1 > degreeCount2){
			temp.polyArray[i] = P1.polyArray[i];
			i++;
			degreeCount1--;
			
		}
		else if (degreeCount2 > degreeCount1){
			temp.polyArray[i] = polyArray[j];
			i++;
			j++;
			degreeCount2--;
			
			}
		}
	}
	return temp;
}

Polynomial Polynomial::operator-(const Polynomial& P1)
{
	
	Polynomial temp; 
	int Min, Max; 
	int degreeCount1, degreeCount2; 
	int i = 0, j = 0;

	if (maxDegree > P1.maxDegree){
		Max = maxDegree;
		Min = P1.maxDegree;
	}
	else if (maxDegree < P1.maxDegree){
		Max = P1.maxDegree;
		Min = maxDegree;
	}
	else if (maxDegree == P1.maxDegree){
		Max = maxDegree; 
		Min = P1.maxDegree; 
	}

	degreeCount1 = Max; 
	degreeCount2 = Min; 

	temp.maxDegree = Max; 
	temp.polyArray = new int[Max];

	while (degreeCount1 != -1 || degreeCount2 != -1){
	if (Max == maxDegree && Min == P1.maxDegree){
		if (degreeCount1 == degreeCount2){
			temp.polyArray[i] = polyArray[i] - P1.polyArray[j];
			i++; 
			j++;
			degreeCount1--;
			degreeCount2--;

		}
		else if (degreeCount1 > degreeCount2){
			temp.polyArray[i] = polyArray[i];
			i++;
			degreeCount1--;
			
		}
		else if (degreeCount2 > degreeCount1){
			temp.polyArray[i] = P1.polyArray[j];
			i++;
			j++;
			degreeCount2--;
			
			}
		}
	else if (Max == P1.maxDegree && Min == maxDegree){
		if (degreeCount1 == degreeCount2){
			temp.polyArray[i] = P1.polyArray[i] - polyArray[j];
			i++; 
			j++;
			degreeCount1--;
			degreeCount2--;

		}
		else if (degreeCount1 > degreeCount2){
			temp.polyArray[i] = P1.polyArray[i];
			i++;
			degreeCount1--;
			
		}
		else if (degreeCount2 > degreeCount1){
			temp.polyArray[i] = polyArray[j];
			i++;
			j++;
			degreeCount2--;
			
			}
		}
	}
	return temp;
}

istream& operator>>(istream& in, Polynomial& P1)
{
	in >> P1.maxDegree; 	

	for (int i = 0; i < P1.maxDegree + 1; i++){
		in >> P1.polyArray[i]; 
	}
	
	return in; 
}

ostream& operator<<(ostream& out, const Polynomial& P1)
{
	int i, degreeCount = P1.maxDegree; 
	
for(i = 0; i < P1.maxDegree + 1; i++){

	//Prints the coefficients
	if (P1.polyArray[i] != 0){
		if (P1.polyArray[i] < 0 && P1.polyArray[i] != -1){
			if (degreeCount == 0){
				out << P1.polyArray[i];
			}
			else if (degreeCount == 1){
				out << P1.polyArray[i] << "x" ; 
			}
			else 
			out << P1.polyArray[i] << "x^" << degreeCount;
		}
		if (P1.polyArray[i] == -1){
			if (degreeCount == 0){
				out << P1.polyArray[i];
			}
			else if (i == 0 && degreeCount != 0){
				out << "-x^" << degreeCount;
			}
			else if (degreeCount == 1){
				out << "-" << "x" ; 
			}
			else
			out << "-" << "x^" << degreeCount;
		}
	
		if (P1.polyArray[i] > 0 && P1.polyArray[i] != 1){
			if (degreeCount == 0){
				out << "+" << P1.polyArray[i];
			}
			else if (i == 0 && degreeCount != 0){
				out << P1.polyArray[i] << "x^" << degreeCount;
			}
			else if (degreeCount == 1){
				out << "+" << P1.polyArray[i] << "x" ; 
			}
			else
			out << "+" << P1.polyArray[i] << "x^" << degreeCount;
		}
		if (P1.polyArray[i] == 1){
			if (degreeCount == 0){
				out << "+" << P1.polyArray[i];
			}
			else if (i == 0 && degreeCount != 0){
				out << "x^" << degreeCount;
			}
			else if (degreeCount == 1){
				out << "+" << "x" ; 
			}
			else
			out << "+" << "x^" << degreeCount;
		}

	
	}
	degreeCount--;
} 
	cout << endl;
	return out;	
}