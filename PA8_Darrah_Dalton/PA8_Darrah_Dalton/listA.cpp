#include <iostream> 
#include "listA.h"

using namespace std;

List::List(int initSize)
{
	size = initSize; 
	actual = 0; 
	cursor = 0;
	data = new int[size+1];
}

List::List(const List& src)
{
	size = src.size; 
	actual = src.actual;
	cursor = src.cursor; 
	data = new int[size];
	for(int i = 0; i < size+1; i++){
	data[i] = src.data[i]; 	
	}
}

List::~List()
{
	size = 0; 
	actual = 0; 
	cursor = 0; 
	delete [] data;
}

bool List::goToBeginning()
{
	if (cursor != 0){
		while(cursor != 0){
			cursor--;
		}
		return true;
	}
	else if (cursor == 0){
		return false;
	}
	return false; 
}

bool List::goToEnd()
{
	if (cursor != size){
		while(cursor != size){
			cursor++;
		}
		return true;
	}
	else if (cursor == size){
		return false;
	}
	return false; 
}

bool List::goToNext()
{
	if(cursor != size){
		cursor++;
		return true;
	}
	if (cursor == size){
		return false;
	}
	return false; 
}

bool List::goToPrior()
{
	if(cursor != 0){
		cursor--;
		return true;
	}
	if (cursor == 0){
		return false;
	}
	return false;
}
              
bool List::insertBefore(int dataInsert)
{
	int T1, T2, i; 
	bool full = isFull();
	T1 = data[cursor];
	T2 = data[cursor+1];
	i = cursor + 1;
	if (full == false){
	data[cursor] = dataInsert;
	actual++;
		while(cursor != actual){
			data[i] = T1; 
		}
		return true; 
	}	
	else 
		return false; 
	
}

bool List::insertAfter(int dataInsert)
{
	bool full = isFull();

	if(full == false){
		cursor++;
		data[cursor] = dataInsert;
		actual++;
		return true;
	}
	else if(full == true){
		return false; 
	}
	return false; 
}

bool List::remove()
{
	int i, t1, t2; 
	List temp; 
	temp.size = size;
	temp.actual = actual;
	temp.cursor = cursor; 
	temp.data = new int[size];
	t1 = cursor; 

	if (cursor != actual){
	while(t1 != actual){
		t2 = data[t1+1];
		data[t1] = t2; 
		t1++;
		t2++;
	}
	actual--;
	return true;
	}
	else if(cursor == actual){
		actual--;
		return false; 
	}
	return false; 
}
              
bool List::isEmpty() const
{
	if(actual == size-1){
		return false;
	}
	else if(actual != size-1){
		return true; 
	}
	return false; 

}

bool List::isFull() const
{
	if(actual == size-1){
		return true;
	}
	else if(actual != size-1){
		return false; 
	}
	return false; 
}

void List::clear()
{
	int tempAct = size; 
	for(int i = 0; i < tempAct; i++){
		cout << "He";
		remove();
		cursor--; 
		actual--;
	}
}

List& List::operator=(const List& src)
{
	size = src.size; 
	actual = src.actual;
	cursor = src.cursor; 
	data = new int[size];
	for(int i = 0; i < size+1; i++){
	data[i] = src.data[i]; 	
	}
}

ostream& operator<<(ostream& out, const List& List)
{
	int i; 

	cout << "Size is: " << List.size << endl;
	cout << "Actual is: " << List.actual << endl;
	cout << "Cursor is at: " << List.cursor << endl; 
	cout << "The Data List : " << endl;
	for (i = 1; i < List.actual + 1; i++){
		if (i == List.cursor){
			out << "[" << List.data[i] << "]" << " ";
		}
		else{ 
			out << List.data[i] << " ";
		}
	}
	cout << endl;
	return out;
}