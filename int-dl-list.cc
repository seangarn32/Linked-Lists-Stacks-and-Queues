#include "int-dl-list.h"
#include <iostream>
using namespace std;

//Sean Garner

const int EMPTY_LIST = 1;

intDLList::~intDLList() {
	for (intDLLNode *p; !isEmpty(); head = p) {
		p = head->next;
		delete head;
	}
}

void intDLList::addToHead(int el) {
	if (head != nullptr) {
		head = new intDLLNode(el, head, nullptr);
		head->next->prev = head;
	}
	else head = tail = new intDLLNode(el);
}

void intDLList::addToTail(int el) {
	if (tail != nullptr) {
		tail = new intDLLNode(el, nullptr, tail);
		tail->prev->next = tail;
	}
	else head = tail = new intDLLNode(el);
}

int intDLList::deleteFromHead() {
	if(!isEmpty()) {
		int el = head->info;
		intDLLNode *tmp = head;
		if (head == tail)
			head = tail = nullptr;
		else
		{
			head = head->next;
			head->prev = nullptr;
		}
		delete tmp;
		return (el);
	}
	else throw(EMPTY_LIST);
}

int intDLList::deleteFromTail() {
	if (head != nullptr) { // if non-empty list
		int el = tail->info;
		if (head == tail) { // if list has just one node
			delete tail;
			head = tail = nullptr;
		}
		else { // if list has >1 node
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}		
		return el;
	}
	else throw(EMPTY_LIST);
}

void intDLList::deleteNode(int el) {
	if (head != nullptr) // if nonempty list
	{
		if (head == tail && el == head->info) { // 1 node in list
			delete head;
			head = tail = nullptr;
		}
		else {
			if (el == head->info) {
				// if > 1 node is in list
				intDLLNode *tmp = head;
				head = head->next;
				delete tmp;
			}
			else {
				intDLLNode *pred, *tmp;
				for (pred = head, tmp = head->next;
					tmp != nullptr && tmp->info != el;
					pred = pred->next, tmp = tmp->next);
				if (tmp != nullptr)
					pred->next = tmp->next;
				if (tmp == tail) tail = pred;
				delete tmp;
			} // inner else ends
		} // outer else ends
	}
	else throw(EMPTY_LIST);
}

bool intDLList::isInList(int el) const {
	intDLLNode *tmp;
	for (tmp = head; tmp != nullptr && tmp->info != el; tmp = tmp->next);
	return (tmp != nullptr);
}

void intDLList::addSorted(int i){
	intDLLNode *tmp;
	intDLLNode *newNode = new intDLLNode(i);
	if(head == nullptr && tail == nullptr)//Checks if list is empty
	{
		cout<<"test"<<endl;
		head = tail = newNode;
	}
	else if (head->info >=i) {//checks head position
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	else if (tail->info <= i){//checks tail position
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else
	{
		for (tmp = head; tmp->next != nullptr; tmp = tmp->next);//Goes through list and finds correct place
		{
			if(tmp->next->info <= i)
			{
				tmp->next->prev = newNode;
				tmp->prev->next = newNode;
			}
		}
	}
}

void intDLList::printlist(){
	intDLLNode *tmp = head;
	while(tmp != nullptr)
	{
		cout<<tmp->info<<endl;
		tmp = tmp->next;
	}
}



