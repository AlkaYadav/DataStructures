/*
 * ReverseSinglyLinkedList.h
 *
 *  Created on: May 13, 2015
 *      Author: alkyadav
 */

#ifndef SRC_SINGLYLINKEDLIST_H_
#define SRC_SINGLYLINKEDLIST_H_

#include "Node.h"
#include<iostream>
using namespace std;

class SinglyLinkedList{
private:
	SingleNode *head;
public:
	SinglyLinkedList();
	void insertAtEnd(int data);
    void reverseSinglyLinkedList(SinglyLinkedList l);
    void printSinglyLinkedList(SinglyLinkedList sl);
};



#endif /* SRC_SINGLYLINKEDLIST_H_ */
