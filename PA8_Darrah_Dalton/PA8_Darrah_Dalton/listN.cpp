#include <iostream> 
#include "listN.h"

using namespace std; 

Node::Node(int val, Node* initNext)
{
	data = val;
	next = initNext; 
}

List::List(int ignore)
{
	head = cursor = NULL;
}

List::List(const List& src)
{
	this -> head = 0; 
	Node *tempHead = src.head; 
	while (tempHead != 0){
		this -> insertAfter(tempHead -> data);
		tempHead = tempHead -> next;
	}
}

List::~List()
{
	clear();
}

bool List::goToBeginning()
{

	if(isEmpty()){
		return false; 
	}
	else 
		cursor = head;
		return true; 

}

bool List::goToEnd()
{

	if(isEmpty()){
		return false; 
	}
	else 
		while(cursor -> next){
			cursor = cursor -> next; 
		}
		return true; 
}

bool List::goToNext()
{

	if(isEmpty() || !cursor -> next){
		return false; 
	}
	else 
		cursor = cursor -> next; 
		return true; 
}

bool List::goToPrior()
{
	if(isEmpty() || cursor == head){
		return false; 
	}
	else{
		Node *temp = head;
		while(temp -> next != cursor){
			temp = temp -> next; 
		}
		cursor = temp; 
		temp = NULL; 
		return true; 
	}
}
              
bool List::insertBefore(int num)
{
	if(isEmpty()){
		Node *temp = new Node(num, NULL);
		head = cursor = temp; 
		temp = NULL;
		return false; 
	}
	else if (cursor == head){
		Node *temp = new Node(num, head);
		head = cursor = temp; 
		temp = NULL;
		return true; 
	}
	goToPrior();
	insertAfter(num);
	return true; 
}

bool List::insertAfter(int num)
{
	Node *temp = new Node(num, (isEmpty() || !cursor -> next) ? NULL : cursor -> next);
	if(isEmpty()){
		head = temp; 
		cursor = head; 
	}
	else{
		cursor -> next = temp; 
		cursor = temp; 
	}
	temp = NULL; 
	return true;
}

bool List::remove()
{
	if(isEmpty()){
		return false; 
	}
	else if(head == cursor){
		delete cursor; 
		head = cursor = NULL; 
		return true; 
	}
	else if(head -> next == NULL){
		head = head -> next; 
		cursor -> next = NULL;
		delete cursor; 
		cursor = head; 
		return true; 
	}
	else{
		Node *temp = head;
		while(temp -> next != cursor){
			temp = temp -> next; 
		}
		temp -> next = cursor -> next; 
		delete cursor; 
			if(temp -> next == NULL){
				cursor = head;
			}
			else{
				cursor = temp -> next;
			}
			temp = NULL; 
			return true; 
	}
}
              
bool List::isEmpty() const
{
	if(head == NULL){
		return true;
	}
	else 
		return false; 
}

bool List::isFull() const
{
	return false; 
}

void List::clear()
{

	while (head){
		head = head -> next; 
	}
	head = NULL; 
	cursor = NULL; 
}

List& List::operator=(const List& src)
{
	if(this != &src){
		head = NULL;
		cursor = NULL; 
		head = new Node(src.head -> data, src.head -> next);
		cursor = head -> next; 
		Node *temp = src.cursor; 
		temp = src.head -> next; 
		temp = temp -> next; 
		while(temp){
			cursor -> next = new Node(temp -> data, temp -> next);
			cursor = cursor -> next; 
			temp = temp -> next; 
		}
	}
	return *this; 
}

ostream& operator<<(ostream& out, const List& list)
{
	if(!list.head){
		out << "The list is Empty." << endl;
	}
	else {
		Node *temp = list.head;
		while(temp){
			if(temp -> data == list.cursor -> data){
				out << "[" << temp -> data << "]" << ' ';
			}
			else{
				out << temp -> data << ' ';
			}
			temp = temp -> next;
		}
		temp = NULL;
		out << endl;
	}
	return out; 
}