#pragma once
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
using namespace std;
template <typename T>
struct node {
	string point1;
	string point2;
	T data;
	node* next;
};
template <class T>
class Lists {
public:
	friend class RBtree;
	friend class tree;
	friend class BFTiterator;
	node<T>* Head;
	node<T>* Tail;
public:
	//	trees treee;
	Lists() :Head(NULL), Tail(NULL) {} //Concstructor
	void push_back(T data);

	void push_front(T);
	void pop_back();
	void pop_front();
	void clear();
	//void insert(int, size_t);
	T at(size_t);
	node<T> at2(size_t);
	void remove(size_t);
	size_t get_size();
	void print_to_console();
	void del();
	void set(size_t, T);
	bool isEmpty_();
	void reverse();
	//	~Lists() { clear(); }//destructor
};
template <typename T>
node<T> Lists<T>::at2(size_t index) {
	if ((index < 0))
		throw out_of_range("error, wrong index");
	if (Head == NULL) {
		throw runtime_error("error, empty list");
	}

	node<T>* save = Head;
	int i = 0;
	while ((i != index) && (save->next != NULL)) {
		save = save->next;
		i++;
	}
	return *save;
}

template <typename T>
void   Lists<T>::push_back(T data) { //add new element at the back

	if (Head != NULL) {
		node<T>* save = NULL;
		save = Tail;
		Tail->next = new node<T>;
		Tail = Tail->next;
		Tail->data = data;
		Tail->next = NULL;
	}
	else
	{
		Head = new node<T>;
		Head->data = data;
		Head->next = NULL;
		Tail = Head;
	}
	//	delete save;
}
template <typename T>
void Lists<T>::push_front(T data) {//ad new elements at the front
	if (Head != NULL) {
		node* save = Head;
		node* newhead = new node;
		newhead->data = data;
		newhead->next = Head;
		Head = newhead;
	}
	else {
		Head = new node;
		Head->data = data;
		Head->next = NULL;
		Tail = Head;
	}
	//	delete save, newhead;
}
template <typename T>
void Lists<T>::pop_front() {//delete an element at the front

	if (Head == NULL)
		return;


	node* save = Head;
	save = Head->next;
	Head = save;
	//	delete save;
}
template <typename T>
void Lists<T>::clear() {//delete all list
	node<T>* t;
	while (Head != NULL) {
		t = Head;
		Head = Head->next;
		delete t;
	}
	Tail = NULL;
}
template <typename T>
void Lists<T>::pop_back() {//delete an element at the back
	if (Head == NULL)
		return;
	node<T>* save = Head;
	if (save->next == NULL) {
		Head = NULL;
		return;
	}
	while (save->next->next != NULL) {
		save = save->next;
	}
	node<T>* savenext = save->next;
	Tail = save;
	save->next = NULL;
	//	delete savenext;
}

template <typename T>
T Lists<T>::at(size_t index) {//take an element



	if ((index < 0))
		throw out_of_range("error, wrong index");
	if (Head == NULL) {
		throw runtime_error("error, empty list");
	}

	node<T>* save = Head;
	int i = 0;
	while ((i != index) && (save->next != NULL)) {
		save = save->next;
		i++;
	}
	return save->data;
}
template <typename T>
void Lists<T>::remove(size_t index) {//delete an element by index


	if ((index < 0) || (index > get_size() - 1))
		throw out_of_range("error, wrong index");

	if (Head == NULL)
		return;



	if (index == 0) {
		node* savehead = Head;
		Head = Head->next;
		delete savehead;
		return;
	}
	node* save = Head;
	int i = 1;
	while (i != index) {
		save = save->next;
		i++;
	}
	if (save->next->next != NULL) {
		save->next = save->next->next;
		save = save->next;
	}
	else {
		Tail = save;
		save->next = NULL;
	}

}
template <typename T>
size_t Lists<T>::get_size() {//get size of the list
	if (Head == NULL) {
		return 0;
	}
	node<T>* save = Head;
	int i = 0;
	while (save->next != NULL) {
		save = save->next;
		i++;
	}
	return i + 1;
}
template <typename T>
void Lists<T>::print_to_console()//print a list at console

{

	fstream output;
	output.open("C:\\Users\\Alex\\Desktop\\output.txt", ios::out);


	node* save = Head;

	while (save != NULL)

	{

		cout << save->data << ",";
		output << save->data << ",";

		save = save->next;

	}
	output.close();

}
template <typename T>
void Lists<T>::set(size_t index, T data) {//change an element by index
	node* save = Head;
	int i = 0;
	if ((index < 0) || (index > get_size() - 1))
		throw out_of_range("error, wrong index");
	if (Head == NULL) {
		return;
	}

	if (index == 0) {
		Head->data = data;
		return;
	}


	while ((i != index) && (save != NULL)) {
		save = save->next;
		i++;
	}
	save->data = data;
}
template <typename T>
void Lists<T>::del()

{

	while (Head != NULL)

	{

		node* save = Head->next;

		cout << Head << " ";

		cout << Head->next << " ";

		delete Head;

		Head = save;

	}

	cout << endl;

}
template <typename T>
bool Lists<T>::isEmpty_() {//test, if list is empty
	if (Head != NULL)  return false;
	else  return true;
}
template <typename T>
void Lists<T>::reverse() {//reverse a list
	if ((Head == NULL) || (Head->next == NULL))
		return;

	node<T>* tail = Head->next;

	node<T>* afterhead = Head->next;

	int i = 0;

	while (tail->next != NULL) {

		tail = tail->next;

		i++;

	}

	i = i + 2;

	node<T>* last = Tail;

	node<T>* beg = Head;

	node<T>* head1 = Head;

	node<T>* last1 = last;

	node<T>* lass = last;

	while (i != 0) {

		if (beg->next == lass) {

			last1 = beg->next;

			last1->next = beg;

			lass = beg;

			beg = Head;

			i--;

		}

		if (i == 0) {

			node<T>* pr = last1->next;

			pr->next = Head;

			i = 0;

		}

		beg = beg->next;

	}

	node<T>* last2 = last;

	last = head1;

	Head = last2;

	last->next = NULL;


}