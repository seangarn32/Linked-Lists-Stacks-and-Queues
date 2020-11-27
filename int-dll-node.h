#ifndef _INT_DLL_NODE_H_
#define _INT_DLL_NODE_H_

class intDLLNode
{
	friend class intDLList;
public:
	intDLLNode(int el=0, intDLLNode *n=nullptr, intDLLNode *p=nullptr) {
		info = el;
		next = n;
		prev = p;
	}
protected:
	int info;
	intDLLNode *next, *prev;

};

#endif // _INT_DLL_NODE_H_

