#include <iostream> 
#include "stackN.h"

using namespace std; 

NodeS::NodeS(int num, NodeS* nSrc)
{
	data = num; 
	next = nSrc; 
}

stackN::stackN()
{
	top = NULL;
}

stackN::stackN(const stackN& nSrc)
{
	cout << "Copy constructor" << endl;
	NodeS *srcTemp;
	NodeS *temp; 

	if(empty()){
		top = NULL; 
	}
	else {
		srcTemp = nSrc.top;
		top = new NodeS(srcTemp -> data, NULL);
		temp = top; 
		srcTemp = srcTemp -> next;
		while(srcTemp != NULL){
			temp -> next = new NodeS(srcTemp -> data, NULL);
 			srcTemp = srcTemp -> next; 
 			temp = temp -> next; 
		}
		temp = NULL; 
	}
}

stackN::~stackN()
{
	cout << "Destructor" << endl;
	clear();
}

stackN& stackN::operator=(const stackN& nSrc)
{
	NodeS *srcTemp;
	NodeS *temp; 

	if(this != &nSrc){
		
		clear();
		srcTemp = nSrc.top;
		top = new NodeS(srcTemp -> data, NULL);
		temp = top; 
		srcTemp = srcTemp -> next;
		while(srcTemp != NULL){
			temp -> next = new NodeS(srcTemp -> data, NULL);
 			srcTemp = srcTemp -> next; 
 			temp = temp -> next; 
		}
		temp = NULL; 
	}
}

bool stackN::push(int num)
{

	if(empty()){
	NodeS *temp = new NodeS(num, NULL);
	top = temp; 
	temp = NULL;  
	return true; 
	} 
	else if(!empty()){
		NodeS *temp = new NodeS(num, NULL);
		temp -> next = top; 
		top = temp; 
		temp = NULL; 
		return true; 
	}
	return false; 
}

bool stackN::pop()
{
	if(!empty()){
	NodeS *temp; 
	temp = top;
	top = temp -> next; 
	temp = NULL; 
	}
	return false; 
}

int stackN::getTop()
{
	if (!empty()){
	return top -> data;
	} 
	return 0;  
}

bool stackN::empty() const 
{
	if(top == NULL){
		return true; 
	}
	return false; 
}

bool stackN::full() const 
{
	return false; 
}

bool stackN::clear()
{
	NodeS *temp;
	if(!empty()){
		while(top != NULL){
			temp = top; 
			top = temp -> next; 
			delete temp;
		}
		temp = NULL;
		return true; 
	}
	return false; 
}

bool stackN::operator==(const stackN& nSrc) const 
{ 
	return false; 
}

ostream& operator<<(ostream& out, const stackN& nSrc)
{
	NodeS *temp = nSrc.top; 
	while(temp != NULL){
	out << temp -> data << " "; 
	temp = temp -> next; 
	}
	temp = NULL;
	out << endl; 
	return out; 
}