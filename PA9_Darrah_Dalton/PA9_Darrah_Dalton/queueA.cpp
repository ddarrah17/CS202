#include <iostream>
#include "queueA.h"

using namespace std;

queueA::queueA(int initSize)
{
        front = 0; 
        rear = -1; 
        max = initSize; 
        data = new int[max];
}

queueA::queueA(const queueA& qSrc)
{
	front = qSrc.front; 
	rear = qSrc.rear; 
	max = qSrc.max;
	data = new int[max];

	for(int i = 0; i < max + 1;i++){
		data[i] = qSrc.data[i]; 
	}
}

queueA::~queueA()
{
	clear();
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
	bool isFull = full();

	if(isFull == false){
		rear++;
		data[rear] = num; 
		return true; 
	}
	else {
        return false; 
    }
}

bool queueA::dequeue()
{
	bool isEmpty = empty();
	if (isEmpty == false){
		rear--; 
		for(int i = 0; i < rear + 1; i++){
			data[i] = data[i + 1];
		}
		return true; 
	}
	else{
        return false;
	}
}

int queueA::getFront()
{
	return data[front]; 
}

bool queueA::empty() const 
{
	if(front == rear + 1){
		return true; 
	}
	else{
        return false; 
	}
}

bool queueA::full() const 
{
	if(rear == max - 1){
		return true; 
	}
	else {
        return false; 
	}
}

bool queueA::clear()
{
	bool isEmpty = empty();
	if(isEmpty == false){
		for (int i = 0; i < rear - 1; i++){
			max = 10; 
			front = 0; 
			rear = -1; 
			delete [] data; 
			data = NULL; 
			return true;
		}
	}
	else {
        return false; 
	}
}

bool queueA::operator==(const queueA& qSrc) const
{
	int count = 0; 

	if (front == qSrc.front && rear == qSrc.rear && max == qSrc.max){
		for(int i = 0; i < rear + 1; i++){
			if(data[count] == qSrc.data[count]){
				count++; 
			}
			else {
				return false;
			}
		}
		return true; 
		}
	else
	{
        return false; 
	}
}

ostream& operator<<(ostream& out, const queueA& qSrc)
{
	int i; 

	for(i = 0; i < qSrc.rear+1; i++){
		out << qSrc.data[i] << " "; 
	}
	out << endl;
        return out; 
}

