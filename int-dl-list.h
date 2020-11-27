#include "int-dll-node.h"
#ifndef _INT_DL_LIST_H_
#define _INT_DL_LIST_H_

//Sean Garner

class intDLList
{
	public:
		intDLList() {head= tail= nullptr;}
		~intDLList();
		bool isEmpty() {return (head == nullptr);}
		void addToHead(int);
		void addToTail(int);
		int deleteFromHead();
		int deleteFromTail();
		void deleteNode(int);
		bool isInList(int) const;
		void addSorted(int i);
		void printlist();
	private:
		intDLLNode *head, *tail;
};

#endif // _INT_DL_LIST_H_

