#include <iostream> 
#include "queueN.h"

using namespace std; 

int main()
{
	queueN a; 

	a.enqueue(1);
	a.enqueue(3);
	a.enqueue(8);
	a.enqueue(5);
	cout << a; 

	a.dequeue();
	// queueN b(a); 
	// queueN c; 
	// c = a; 
	// cout << b; 

	// a.clear();
	// cout << "A is " << a; 
	// cout << "C is " << c; 
	return 0; 
}