#include <iostream> 
using namespace std; 

int factorial (int num)
{
	int total = 1; 
	int temp = num + 1; 
	temp--; 
	if(temp != 0){
		total = total * temp; 
		return factorial(temp);
	}
	else 
		return total; 
}

int main()
{
	int a = 3; 

	int b; 

	b = factorial(a);

	cout << b << endl; 
	return 0; 
}