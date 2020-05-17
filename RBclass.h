#pragma once
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include "temp_list.h"
using namespace std;
template <typename T>
struct element {
	T key;
	T data;
};
template <typename T>
struct trenode {
	element<T> data;
	trenode* left;
	trenode* right;
	trenode* parent;
	int color;//0-black,1-red
};


template <class T>
class red_black {
public:
	trenode<T>* Head;
	node<trenode<T>>* current = new node<trenode<T>>;
	node<T>* node3 = new node<T>;
	Lists<trenode<T>>* list = new Lists<trenode<T>>();
	Lists<T>* list2 = new Lists<T>();
	red_black() : Head(NULL) {};
	void insert(trenode<T>*& Head, T data, T key);
	void remove(trenode<T>*& Head, T key);
	trenode<T>* find(trenode<T>* Head, T key);
	void print(trenode<T>** w, int l);
	void printcolors(trenode<T>** w, int l);
	void clear(trenode<T>*& tree) {
		if (tree->left)   clear(tree->left);
		if (tree->right)  clear(tree->right);
		tree = NULL;
		delete tree;
	}
	void get_key(trenode<T>* nod) {
		if (nod == nullptr) {
			current = (list->Head);
			return;
		}

		get_key(nod->left);
		list->push_back(*nod);
		list2->push_back(nod->data.key);
		get_key(nod->right);
	}

	node<T> get_key_all(trenode<T>* nod) {
		get_key(nod);
		return *list2->Head;
	}
	void get_value(trenode<T>* nod) {
		if (nod == nullptr) {
			current = (list->Head);
			return;
		}

		get_value(nod->left);
		list->push_back(*nod);
		list2->push_back(nod->data.data);
		get_value(nod->right);
	}

	node<T> get_value_all(trenode<T>* nod) {
		get_value(nod);
		return *list2->Head;
	}
	//////////////////////////////////////////////////////////////////
	void fix(trenode<T>*& Head, trenode<T>* trenode);
	void leftrotate(trenode<T>*& Head, trenode<T>*& cur);
	void rightrotate(trenode<T>*& Head, trenode<T>*& cur);
	trenode<T>* place(trenode<T>* x);
	trenode<T>* successor(trenode<T>* x);
	~red_black() {
		if (Head != NULL)
			clear(Head);
	}
	void fixblack(trenode<T>*& Head, trenode<T>* x);
	bool isOnLeft(trenode<T>* x) { return x->parent->left == x; }
	trenode<T>* sibling1(trenode<T>* x);
};
template <typename T>
trenode<T>* red_black<T>::find(trenode<T>* Head, T key) {
	trenode<T>* save = Head;
	int check = 0;
	while ((save != NULL)) {
		if (save->data.key > key)
			save = save->left;
		else if (save->data.key < key)
			save = save->right;
		else
			break;
	}
	if (save == NULL)
		throw runtime_error("we cant find a node");
	if (save->data.key == key)
		return save;
}
template <typename T>
trenode<T>* red_black<T>::successor(trenode<T>* x) {
	trenode<T>* temp = x;

	while (temp->left != NULL)
		temp = temp->left;

	return temp;
}
template <typename T>
trenode<T>* red_black<T>::place(trenode<T>* x) {
	bool left = false, right = false;
	trenode<T>* check = x;
	while (check != Head) {
		if (check->parent->left == x)
			left = true;
		check = check->parent;
	}
	check = x;
	while (check != Head) {
		if (check->parent->right == x)
			right = true;
		check = check->parent;
	}
	if (left == true) {
		if ((x->left != NULL) && (x->right != NULL)) //2 child
			return successor(x->right);
	}
	if (right == true) {
		if ((x->left != NULL) && (x->right != NULL)) //2 child
			return successor(x->left);
	}
	if ((x->left == NULL) && (x->right == NULL))//leaf
		return NULL;
	if (x->left != NULL)
		return x->left;
	else
		return x->right;
}
template <typename T>
void red_black<T>::remove(trenode<T>*& Head, T key) {
	trenode<T>* run = Head;
	while (run->data.key != key) {
		if ((run->data.key > key)) {
			if (run->left == NULL)
				break;
			if (run->left != NULL) {
				if (run->left->data.key == key) {
					run = run->left;
					break;
				}
			}
			if (run->right != NULL) {
				if (run->right->data.key == key)
					run = run->right;
				else
					if (run->data.key > key)
						run = run->left;
			}
			else
				run = run->left;
		}
		if ((run->data.key < key)) {
			if (run->right == NULL)
				break;
			if (run->right->data.key == key) {
				run = run->right;
				break;
			}
			else
				if (run->left != NULL)
					if (run->left->data.key == key)
						run = run->left;
					else
						run = run->right;
		}
	}
	trenode<T>* U = place(run);
	bool check = (((U == NULL) || (U->color == 0)) && (run->color == 0));
	trenode<T>* par = run->parent;
	if (U == NULL) {
		if (run == Head) {
			Head = NULL;
		}
		else {
			if (check) {
				fixblack(Head, run);
			}
			else
			{
				if (sibling1(run) != NULL)
					sibling1(run)->color == 1;
			}
			if (isOnLeft(run)) {
				run->parent->left == NULL;
			}
			else
			{
				run->parent->right = NULL;
			}
		}
		if (run->parent != NULL) {
			if ((run->parent->left == run))
				run->parent->left = NULL;
			else
				run->parent->right = NULL;
		}
		delete run;
		return;
	}
	if ((run->left == NULL) || (run->right == NULL)) {
		if (run == Head) {
			run->data = U->data;
			run->left == run->left == NULL;
			delete U;
		}
		else
		{
			if (isOnLeft(run)) {
				run->parent->left = U;
			}
			else
			{
				run->parent->right = U;
			}
			trenode<T>* par = run->parent;
			delete run;
			U->parent = par;
			if (check) {
				fixblack(Head, U);
			}
			else
			{
				U->color = 0;
			}
		}
		return;
	}
	element<T> save = run->data;
	run->data = U->data;
	U->data = save;

	remove(Head, U->data.key);
}

template <typename T>
void red_black<T>::insert(trenode <T>*& Head, T data, T key) {
	trenode<T>* cur = Head;
	trenode<T>* save = Head;
	if (Head == NULL) {
		Head = new trenode<T>;
		Head->data.data = data;
		Head->data.key = key;
		Head->color = 0;
		Head->left = NULL;
		Head->right = NULL;
		Head->parent = NULL;
		return;
	}
	if (Head != NULL) {
		while (cur != NULL) {
			save = cur;
			if (key > cur->data.key) {
				cur = cur->right;
			}
			else if (key < cur->data.key) {
				cur = cur->left;
			}
			else if (key == cur->data.key) {
				cur->data.data = data;
				break;
			}
		}
		if (save->data.key > key) {
			save->left = new trenode<T>;
			save->left->parent = save;
			save->left->data.data = data;
			save->left->data.key = key;
			save->left->color = 1;
			save->left->left = NULL;
			save->left->right = NULL;
			save = save->left;
		}
		else if (save->data.key < key) {
			save->right = new trenode<T>;
			save->right->parent = save;
			save->right->data.data = data;
			save->right->data.key = key;
			save->right->color = 1;
			save->right->right = NULL;
			save->right->left = NULL;
			save = save->right;
		}
	}
	if (save->parent != Head)
		fix(Head, save);
}

template <typename T>
void red_black<T>::fix(trenode<T>*& Head, trenode<T>* node1) {
	trenode<T>* par = NULL;
	trenode<T>* gpar = NULL;
	while ((node1 != Head) && (node1->color != 0) && (node1->parent->color == 1)) {
		par = node1->parent;
		gpar = node1->parent->parent;
		//case A
		if ((par == gpar->left))
		{
			trenode<T>* uncle = gpar->right;
			//case 1
			if ((uncle != NULL) && (uncle->color == 1)) {
				gpar->color = 1;
				par->color = 0;
				uncle->color = 0;
				node1 = gpar;
			}
			else
				//case 2
			{
				if (node1 == par->right) {
					leftrotate(Head, par);
					node1 = par;
					par = node1->parent;
					break;
				}
				rightrotate(Head, gpar);
				int save = 0;
				save = par->color;
				par->color = gpar->color;
				gpar->color = save;
				node1 = par;
			}
		}
		//case B
		else
		{ //case 1
			trenode<T>* uncle = gpar->left;
			if ((uncle != NULL) && (uncle->color == 1)) {
				gpar->color = 1;
				par->color = 0;
				uncle->color = 0;
				node1 = gpar;
			}
			else //case 2
			{
				if (node1 == par->left) {
					rightrotate(Head, par);
					node1 = par;
					par = node1->parent;
					break;
				}
				//case 3
				leftrotate(Head, gpar);
				int save = 0;
				save = par->color;
				par->color = gpar->color;
				gpar->color = save;
				node1 = par;
			}
		}
	}
	Head->color = 0;
}

template <typename T>
void red_black<T>::leftrotate(trenode<T>*& Head, trenode<T>*& cur) {
	trenode<T>* pt_right = cur->right;

	cur->right = pt_right->left;

	if (cur->right != NULL)
		cur->right->parent = cur;

	pt_right->parent = cur->parent;

	if (cur->parent == NULL)
		Head = pt_right;

	else if (cur == cur->parent->left)
		cur->parent->left = pt_right;

	else
		cur->parent->right = pt_right;

	pt_right->left = cur;
	cur->parent = pt_right;
}

template <typename T>
void red_black<T>::rightrotate(trenode<T>*& Head, trenode<T>*& cur) {
	trenode<T>* pt_left = cur->left;

	cur->left = pt_left->right;

	if (cur->left != NULL)
		cur->left->parent = cur;

	pt_left->parent = cur->parent;

	if (cur->parent == NULL)
		Head = pt_left;

	else if (cur == cur->parent->left)
		cur->parent->left = pt_left;

	else
		cur->parent->right = pt_left;

	pt_left->right = cur;
	cur->parent = pt_left;
}
template <typename T>
void red_black<T>::fixblack(trenode<T>*& Head, trenode<T>* x) {
	if (x == Head)
		// Reached root 
		return;

	trenode<T>* sibling = sibling1(x), * parent = x->parent;
	if (sibling == NULL) {
		// No sibiling, double black pushed up 
		fixblack(Head, parent);
	}
	else {
		if (sibling->color == 1) {
			// Sibling red 
			parent->color = 1;
			sibling->color = 0;
			if (isOnLeft(sibling)) {
				// left case 
				rightrotate(Head, parent);
			}
			else {
				// right case 
				leftrotate(Head, parent);
			}
			fixblack(Head, x);
		}
		else {
			// Sibling black 
			if (((sibling->left != NULL) && (sibling->left->color == 1)) || ((sibling->right != NULL) && (sibling->right->color == 1))) {
				// at least 1 red children 
				if ((sibling->left != NULL) && (sibling->left->color == 1)) {
					if (isOnLeft(sibling)) {
						// left left 
						sibling->left->color = sibling->color;
						sibling->color = parent->color;
						rightrotate(Head, parent);
					}
					else {
						// right left 
						sibling->left->color = parent->color;
						rightrotate(Head, sibling);
						leftrotate(Head, parent);
					}
				}
				else {
					if (isOnLeft(sibling)) {
						// left right 
						sibling->right->color = parent->color;
						leftrotate(Head, sibling);
						rightrotate(Head, parent);
					}
					else {
						// right right 
						sibling->right->color = sibling->color;
						sibling->color = parent->color;
						leftrotate(Head, parent);
					}
				}
				parent->color = 0;
			}
			else {
				// 2 black children 
				sibling->color = 1;
				if (parent->color == 0)
					fixblack(Head, parent);
				else
					parent->color = 0;
			}
		}
	}
}
template <typename T>
trenode<T>* red_black<T>::sibling1(trenode<T>* x) {
	// sibling null if no parent 
	if (x->parent == NULL)
		return NULL;

	if (isOnLeft(x))
		return x->parent->right;

	return x->parent->left;
}
template<typename T>
void red_black<T>::print(trenode<T>** w, int l)

{

	int i;

	if (*w != NULL)
	{
		print(&((**w).right), l + 1);
		for (i = 1; i <= l; i++) cout << "   ";
		cout << (**w).data.key << endl;


		print(&((**w).left), l + 1);
	}
}
template<typename T>
void red_black<T>::printcolors(trenode<T>** w, int l)

{

	int i;

	if (*w != NULL)
	{
		printcolors(&((**w).right), l + 1);
		for (i = 1; i <= l; i++) cout << "   ";
		cout << (**w).color << endl;


		printcolors(&((**w).left), l + 1);
	}
}