#include <iostream> 
using namespace std; 

class Polynomial {
	
	public: 
		Polynomial();
		Polynomial(int deg, int *arrayPtr);
		Polynomial(const Polynomial&);
		~Polynomial();
		int solve(int) const; 
		Polynomial& operator=(const Polynomial&);
		bool operator==(const Polynomial&);
		bool operator!=(const Polynomial&);
		Polynomial operator*(const Polynomial&);
		Polynomial operator*(const int);
		Polynomial operator+(const Polynomial&);
		Polynomial operator-(const Polynomial&);
		friend istream& operator>>(istream&, Polynomial&);
		friend ostream& operator<<(ostream&, const Polynomial&);

	private: 
		int* polyArray;
		int maxDegree; 

};