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
	front = NULL;
	rear = NULL; 
}

queueN::queueN(const queueN& nSrc)
{
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
	 	NodeQ *temp = new NodeQ(num, NULL);
	 	front = temp; 
	 	rear = front; 
	 	return true; 
	 }
	 else if(!empty()){
	 	NodeQ *temp = new NodeQ(num, NULL);	
	 	rear -> next = temp;
	 	rear = temp; 
	 	return true; 
    }
	return false; 
}

bool queueN::dequeue()
{
	if (!empty()){
		NodeQ *temp; 
		temp = front; 
		front = front -> next; 
		delete temp; 
		temp = NULL;
		return true; 
	}

	return false; 
}

int queueN::getFront()
{
	if(!empty()){
		return front -> data;
	}
	return 0; 
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
	NodeQ *temp = nSrc.front;
 	NodeQ *temp2 = front;

 if(empty() && nSrc.empty()) {
   return true;
 }
 else if(!empty()) {
   while(temp != NULL) {
     if(temp->data != temp2->data) {
       return false;
      }
     temp = temp->next;
     temp2 = temp2->next;
    }
   return true;
  }
}

ostream& operator<<(ostream& out, const queueN& nSrc)
{
	NodeQ *temp = nSrc.front; 
	while (temp != NULL){
		out << temp -> data << " ";
		temp = temp -> next; 
	}
	temp = NULL; 
	out << endl;
	return out; 
}