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
 NodeS *temp = nSrc.top;
 NodeS *temp2 = top;

 if(empty() && nSrc.empty()) {
   return true;
 }
 else if(empty() || nSrc.empty()) {
   return false;
 }
 else {
   while(temp != NULL) {
     if(temp->data != temp->data) {
       return false;
      }
     temp = temp->next;
     temp2 = temp2->next;
    }
   return true;
  }
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