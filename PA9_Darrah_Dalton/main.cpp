#include <iostream> 
#include "stackN.h"

using namespace std; 

int main()
{
	stackN a; 
	

	a.push(1);
	a.push(3);
	a.push(5);
	a.push(7);

	cout << "A list is this (should be 7 5 3 1): " << endl;
	cout << a; 

	stackN b(a);

	cout << "B list is this (should be 7 5 3 1): " << endl;
	cout << b; 

	stackN c; 

	c = a;

	cout << "C list is this (should be 7 5 3 1): " << endl;
	cout << c;

	int k = a.getTop();
	cout << "The top of a is : " << k << endl;
	k = b.getTop();
	cout << "The top of b is : " << k << endl;
	k = c.getTop();
	cout << "The top of c is : " << k << endl;
	a.clear();
	

	return 0; 
}