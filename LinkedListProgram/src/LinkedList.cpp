//============================================================================
// Name        : LinkedList.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Node.h"
using namespace std;

class LinkedList {
private:
	Node *start;
	Node *end;
public:
	LinkedList();
	//~LinkedList();
	void add_at_start(int);
	void add_at_end(int);
	void add_at_middle(int);
	int del_from_start();
	int del_from_end();
	void printList();
};

LinkedList::LinkedList(){
	start = NULL;
	end = NULL;
}
void LinkedList::add_at_start(int item)
{
    Node *node = new Node();
    if(start == NULL)
    {
    	node->data = item;
    	node->next = NULL;
    	start = node;
    	end = node;
    }
    else
    {
    	node->data = item;
    	node->next = start;
    	start = node;
    }
}

void LinkedList::printList() {
	Node *temp;
	temp = start;
	cout<<"\n";
	while (temp) {
		cout << temp->data << "->";
		temp = temp->next;
	}
}

void LinkedList::add_at_end(int item)
{
	Node *node = new Node();
	node->data = item;
    if(start == NULL)
    {
    	node->next = start;
    	start = node;
    	end = node;
    }

    else
    {
    	end->next = node;
    	node->next = NULL;
    	end = node;
    }
}

int LinkedList::del_from_start()
{
	int item;
    if(start == NULL)
    {
    	cout<<"List empty";
    	return 0;
    }
    else if(start->next == NULL)
    {
    	item = start->data;
    	start = NULL;
    	end = NULL;
    }
    else{
    	item = start->data;
    	start = start->next;
    }
    return item;
}

int LinkedList::del_from_end()
{
	int item;
	    if(start == NULL)
	    {
	    	cout<<"List empty";
	    	return 0;
	    }
	    else if(start->next == NULL)
	    {
	    	item = start->data;
	    	start = NULL;
	    	end = NULL;
	    }
	    else{
	        	item = end->data;
	        	Node *tmp = start;
	        	while(tmp->next != end)
	        		tmp = tmp->next;
	        	tmp->next = NULL;
	        	end = tmp;
	        }
	    return item;
}
int main(int argc, char **argv) {
	LinkedList la;
	cout << "Alka\n";
	la.add_at_start(5);
	la.printList();
	la.add_at_start(6);
	la.printList();
	la.add_at_end(7);
	la.printList();
	cout<<"\nDeleting:";
    la.del_from_start();
	la.printList();
}
