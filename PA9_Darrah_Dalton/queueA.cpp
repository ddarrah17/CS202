#include <iostream>
#include "queueA.h"

using namespace std;

queueA::queueA(int initSize)
{
		cout << "default constructor" << endl;
        front = -1; 
        rear = -1; 
        max = initSize; 
        data = new int[max];
}

queueA::queueA(const queueA& qSrc)
{
	cout << "Copy constructor" << endl;
	front = qSrc.front; 
	rear = qSrc.rear; 
	max = qSrc.max;
	data = new int[max];

	for(int i = 0; i < rear+1;i++){
		data[i] = qSrc.data[i]; 
	}
}

queueA::~queueA()
{
	cout << "Destructor" << endl;
	front = -1; 
	rear = -1; 
	max = 0; 
	delete [] data; 
}

queueA& queueA::operator=(const queueA& qSrc)
{
	front = qSrc.front; 
	rear = qSrc.rear; 
	max = qSrc.max;
	for(int i = 0; i < rear+1;i++){
		data[i] = qSrc.data[i]; 
	}
}

bool queueA::enqueue(int num)
{
	bool isEmpty = empty();

	if(isEmpty == true){
		front = 0; 
		data[front] = num; 
		rear = front; 
		return true; 
	}
	else {
		rear++;
		data[rear] = num; 
		cout << "rear is: " << rear << endl; 
		return true;
	}
        return false; 
}

bool queueA::dequeue()
{
	bool isEmpty = empty();
	if (isEmpty == true){
		return false; 
	}
	else
		data[front] = 0; //Front needs to come off
		front++;
		cout << "front is: " << front << endl; 
        return true;
}

int queueA::getFront()
{
	return data[front]; 
}

bool queueA::empty() const 
{
	if(front == -1){
		return true; 
	}
	else
        return false; 
}

bool queueA::full() const 
{
	if(rear == max){
		return true; 
	}
	else 
        return false; 
}

bool queueA::clear()
{
	bool isEmpty = empty();
	if(isEmpty == false){
		while (rear != -1){
		data[rear] = -1; 
		rear--;  
		}
		front = -1; 
		return true;
	}
        return false; 
}

bool queueA::operator==(const queueA& qSrc) const
{
	int count = 0; 

	if (front == qSrc.front && rear == qSrc.rear && max == qSrc.max){
		for(int i = 0; i < rear+1; i++){
			if(data[i] == qSrc.data[i]){
				count++; 
			}
		}
		if (count == rear+1){
			return true;
		}
		return false; 
	}
        return false; 
}

ostream& operator<<(ostream& out, const queueA& qSrc)
{
	int i; 

	out << "Printing the data list..." << endl << endl << endl;
	out << "Data list: " << endl;
	for(i = qSrc.front; i < qSrc.rear+1; i++){
		out << qSrc.data[i] << "\t"; 
	}
	out << endl;
        return out; 
}

