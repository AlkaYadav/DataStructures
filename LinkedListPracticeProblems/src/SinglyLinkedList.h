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
#include<stack>
using namespace std;

class SinglyLinkedList{
private:
	SingleNode *head;

	void reverseSinglyLinkedList_recursiveHelper(SingleNode *head);


public:
	SinglyLinkedList();
	void insertAtEnd(int data);
	void insertSortedLinkedList(int data);
    void reverseSinglyLinkedList();
    void reverseSinglyLinkedList_recursive();
    bool checkIfListPalindrome();
    bool checkIfListPalindrome_usingStack();
    bool checkIfListPalindrome_usingNoStorage();
    void createDummyList();
    bool checkIfLoopInList();
    void printSinglyLinkedList();
    int lengthOfLinkedList();
    void deleteLinkedList();
    void printNthNodeFromEndLinkedList(int n);
};



#endif /* SRC_SINGLYLINKEDLIST_H_ */
