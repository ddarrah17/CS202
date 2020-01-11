#include <iostream>
#include "stackA.h"

using namespace std; 

stackA::stackA(int initSize)
{
	cout << "Default constructor" << endl;
	top = -1; 
	max = initSize;
	data = new int[max];
}

stackA::stackA(const stackA& sSrc)
{
	cout << "Copy constructor" << endl;
	top = sSrc.top;
	max = sSrc.max; 
	data = new int[max];
	for(int i = 0; i < top+1; i++){
		data[i] = sSrc.data[i];
	}
}

stackA::~stackA()
{
	cout << "Destructor" << endl;
	top = -1; 
	max = 0; 
	delete [] data; 
}

stackA& stackA::operator=(const stackA& sSrc)
{
	top = sSrc.top;
	max = sSrc.max; 
	for(int i = 0; i < top+1; i++){
		data[i] = sSrc.data[i];
	}
}

bool stackA::push(int val)
{
	bool isFull = full();

	if(isFull == false){
		top++;
		data[top] = val;
		cout << "Pushing " << val << "!" << endl;
		return true; 
	}
	return false; 
}

bool stackA::pop()
{
	bool isEmpty = empty();

	if(isEmpty == false){
		cout << "Popping " << data[top] << "!" << endl;
		data[top] = -1;
		top--;
		return true; 
	}
	return false; 
}

int stackA::getTop()
{
	return data[top];
}

bool stackA::empty() const
{
	if(top != -1){
		return false;
	}
	else 
	return true; 
}

bool stackA::full() const 
{
	if (top == max){
		return true; 
	} 
	else
	return false; 
}

bool stackA::clear()
{
	bool isEmpty = empty();

	while (top != -1){
		data[top] = -1;
		top--;
	}
	if(isEmpty == true){
		return true;
	}
	else
	return false; 
}

bool stackA::operator==(const stackA& sSrc) const 
{
	int checkCount = 0; 

	if (top == sSrc.top){

		for (int i = 0; i < top+1; i++){
			if (data[i] == sSrc.data[i]){
				checkCount++;
			}
		}
		if (checkCount == top+1){
			return true; 
		}
		return false; 
	}
	else 	
		return false; 

}

ostream& operator<<(ostream& out, const stackA& sSrc)
{
	int i; 

	out << "Printing data list..." << endl << endl << endl;
	out << "Data list: " << endl;
	for(i = sSrc.top; i > -1; i--){
	out << sSrc.data[i] << endl;
	}
	return out; 
}