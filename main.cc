#include <iostream>
#include <ctime>
#include "int-dl-list.h"
#include "int-dll-node.h"

using namespace std;

//Sean Garner

int main() {
	while (1) {
		int choice;
		cout<<"(1) Create an unsorted list."<<endl;
		cout<<"(2) Create a sorted list."<<endl;
		cout<<"(3) Create a queue."<<endl;
		cout<<"(4) Create a stack."<<endl;
		cout<<"(5) Exit."<<endl;
		cin>>choice;
		intDLList list;
		int a = 1;
		int el;
		switch (choice) {
			case 1: //Create Unsorted List
					while(a)
					{
						cout<<"(1) Insert at head of list."<<endl;
						cout<<"(2) Insert at tail of list."<<endl;
						cout<<"(3) Dsiplay and delete from head of list."<<endl;
						cout<<"(4) Display and delete from tail of list."<<endl;
						cout<<"(5) Search and delete an integer."<<endl;
						cout<<"(6) Display contents from head to tail."<<endl;
						cout<<"(7) Exit."<<endl;
						cin >> choice;
						switch (choice) {
							case 1://Insert at head
								cout<<"Enter int to insert at the head of the list:"<<endl;
								cin>>el;
								list.addToHead(el);
								break;
							case 2://Insert at tail
								cout<<"Enter int to insert at the tail of the list:"<<endl;
								cin>>el;
								list.addToTail(el);
								break;
							case 3://Delete at head
								try {
									el = list.deleteFromHead();
									cout<<"Int at head has been deleted, it was "<<el<<endl;
								} catch (int error_code)
									{
										cerr << " Error: " << error_code << endl;
										switch (error_code)
										{ 
											case 1: 
												cout<<"The list is empty."<<endl;
												break;
											default:
												cout<<"Unknown Error."<<endl;
										}
									}//catch ends
								break;
							case 4://Delete at tail
								try {
									el = list.deleteFromTail();
									cout<<"Int at tail has been deleted, it was "<<el<<endl;
								} catch (int error_code)
									{
										cerr << " Error: " << error_code << endl;
										switch (error_code)
										{ 
											case 1: 
												cout<<"The list is empty."<<endl;
												break;
											default:
												cout<<"Unknown Error."<<endl;
										}
									}//catch ends
								break;
							case 5://Selective delete
								cout<<"Enter node to delete."<<endl;
								cin>>el;
								try {
									list.deleteNode(el);
									cout<<el<<" has been deleted."<<endl;
								} catch (int error_code)
									{
										cerr << " Error: " << error_code << endl;
										switch (error_code)
										{ 
											case 1: 
												cout<<"The list is empty."<<endl;
												break;
											default:
												cout<<"Unknown Error."<<endl;
										}
									}//catch ends
								break;
							case 6://List print
								cout<<"List is: "<<endl;
								list.printlist();
								cout<<endl;
								break;
							case 7://Exit
								a = 0;
								cout<<"Exited unsorted list."<<endl;
								break;
							default:
								cout << endl << "Incorrect selection, try again from the menu below." << endl;
						}
					}
					break;
			case 2: //Create Sorted List
					while(a)
					{
						cout<<"(1) Insert an integer sorted from least to greatest."<<endl;
						cout<<"(2) Search and delete an integer."<<endl;
						cout<<"(3) Display contents from head to tail."<<endl;
						cout<<"(4) Exit."<<endl;
						cin >> choice;
						switch (choice) {
							case 1://Insert sorted
								cout<<"Enter int to insert sorted"<<endl;
								cin>>el;
								list.addSorted(el);
								break;
							case 2://Delete a node
								cout<<"Enter node to delete."<<endl;
								cin>>el;
								try {
									list.deleteNode(el);
									cout<<el<<" has been deleted."<<endl;
								} catch (int error_code)
									{
										cerr << " Error: " << error_code << endl;
										switch (error_code)
										{ 
											case 1: 
												cout<<"The list is empty."<<endl;
												break;
											default:
												cout<<"Unknown Error."<<endl;
										}
									}//catch ends
								break;
							case 3://List print
								cout<<"List is: "<<endl;
								list.printlist();
								cout<<endl;
								break;
							case 4://Exit
								a = 0;
								cout<<"Exited sorted list."<<endl;
								break;
							default:
								cout << endl << "Incorrect selection, try again from the menu below." << endl;

						}
					}
					break;
			case 3: //Create Queue
					while(a)
					{
						cout<<"(1) Insert an integer into the queue"<<endl;
						cout<<"(2) Delete an integer from the queue."<<endl;
						cout<<"(3) Display contents from head to tail."<<endl;
						cout<<"(4) Exit."<<endl;
						cin >> choice;
						switch(choice){
							case 1://New node to insert into queue
								cout<<"Enter integer into the queue."<<endl;
								cin>>el;
								list.addToHead (el);
								break;
							case 2://Display and delete
								try {
									el = list.deleteFromTail();
									cout<<"Int at tail has been deleted, it was "<<el<<endl;
								} catch (int error_code)
									{
										cerr << " Error: " << error_code << endl;
										switch (error_code)
										{ 
											case 1: 
												cout<<"The list is empty."<<endl;
												break;
											default:
												cout<<"Unknown Error."<<endl;
										}
									}//catch ends
								break;
							case 3://Print
								cout<<"Queue is: "<<endl;
								list.printlist();
								cout<<endl;
								break;
							case 4://Exit
								a = 0;
								cout<<"Exited queue."<<endl;
								break;
							default:
								cout << endl << "Incorrect selection, try again from the menu below." << endl;
						}
					}
					break;
			case 4: //Create Stack
					while(a)
					{
						cout<<"(1) Push an integer onto the stack."<<endl;
						cout<<"(2) Pop an integer from the stack."<<endl;
						cout<<"(3) Display contents from starting from the bottom of the stack."<<endl;
						cout<<"(4) Exit."<<endl;
						cin >> choice;
						switch(choice){
							case 1://Push
								cout<<"Enter integer onto the stack."<<endl;
								cin>>el;
								list.addToTail (el);
								break;
							case 2://Pop
								
								try {
									el = list.deleteFromTail();
									cout<<"Popped an integer from the stack";
									cout<<", int was "<<el<<endl;
								} catch (int error_code)
									{
										cerr << "Error: " << error_code << endl;
										switch (error_code)
										{ 
											case 1: 
												cout<<"The list is empty."<<endl;
												break;
											default:
												cout<<"Unknown Error."<<endl;
										}
									}//catch ends
								break;
							case 3://Print
								cout<<"Stack: "<<endl;
								list.printlist ();
								cout<<endl;
								break;
							case 4://Exit
								a = 0;
								cout<<"Exited stack"<<endl;
								break;
							default:
								cout << endl << "Incorrect selection, try again from the menu below." << endl;
						}
					}
					break;
			case 5: // Exit Program
					cout << endl << "Program quit." << endl << endl;
					return 0;

			default: // Error in selection
					cout << endl << "Incorrect selection, try again from the menu below." << endl;
					break;

		} // switch
	} // while
	return 0;
}
