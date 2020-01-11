#include <iostream>
#include "queueN.h"

using namespace std; 

NodeQ::NodeQ(int num, NodeQ* Q)
{
	data = num; 
	next = Q; 
}

queueN::queueN()
{
	cout << "Default constructor" << endl;
	front = NULL;
	rear = NULL; 
}

queueN::queueN(const queueN& nSrc)
{
	cout << "Copy constructor" << endl;
	NodeQ *srcTemp;
	NodeQ *temp; 

	if(empty()){
		front = NULL;
		rear = NULL;
	}
	else 
		srcTemp = nSrc.front;
		front = new NodeQ(srcTemp -> data, NULL);
		temp = front; 
		srcTemp = srcTemp -> next; 
	while(srcTemp != NULL){
 		temp -> next = new NodeQ(srcTemp -> data, NULL);
 		srcTemp = srcTemp -> next; 
 		temp = temp -> next; 
 	}
 	rear = temp; 
 	temp = NULL;
}

queueN::~queueN()
{
	cout << "Destructor" << endl;
	clear();
}

queueN& queueN::operator=(const queueN& nSrc)
{
	NodeQ *srcTemp;
	NodeQ *temp; 

	if(this != &nSrc){
		clear();
		srcTemp = nSrc.front;
		front = new NodeQ(srcTemp -> data, NULL);
		temp = front; 
		srcTemp = srcTemp -> next; 
	while(srcTemp != NULL){
 		temp -> next = new NodeQ(srcTemp -> data, NULL);
 		srcTemp = srcTemp -> next; 
 		temp = temp -> next; 
 	}
 	rear = temp; 
 	temp = NULL;
	}
	return *this; 
}

bool queueN::enqueue(int num)
{
	 if (empty() == true ){
	 	cout << "We are putting this in the queue: " << num << endl;
	 	NodeQ *temp = new NodeQ(num, NULL);
	 	front = temp; 
	 	front -> next = temp -> next; 
	 	rear = front; 
	 	temp -> next = rear; 
	 	return true; 
	 }
	 else if(!empty()){
	 	cout << "We are putting this in the queue: " << num << endl;
	 	NodeQ *temp = new NodeQ(num, NULL);	
	 	rear = temp;
	 	return true; 
    }
	return false; 
}

bool queueN::dequeue()
{
	if (front -> next == NULL){
		cout << "Hello";
	}
	else 
		cout << "NO";
	return false; 
}

bool queueN::empty() const
{	
	if(front != NULL){
		return false; 
	}
	return true; 
}

bool queueN::full() const 
{
	return false; 
}

bool queueN::clear()
{
	NodeQ *temp; 
	if(!empty()){
		while(front != NULL){
			temp = front; 
			front = temp -> next; 
			delete temp; 
		}
		temp = NULL; 
		return true; 
	}
	return false; 
}

bool queueN::operator==(const queueN& nSrc) const
{
	return false; 
}

ostream& operator<<(ostream& out, const queueN& nSrc)
{
	NodeQ *temp = nSrc.front; 
	while (temp != NULL){
		out << "Yellow" << endl;
		out << temp -> data << " ";
		temp = temp -> next; 
	}
	temp = NULL; 
	out << endl;
	return out; 
}