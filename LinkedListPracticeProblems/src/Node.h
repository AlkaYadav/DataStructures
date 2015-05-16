/*
 * Node.h
 *
 *  Created on: May 16, 2015
 *      Author: alkyadav
 */

#ifndef SRC_NODE_H_
#define SRC_NODE_H_

class SingleNode{
	int data;
	SingleNode *next;
	friend class SinglyLinkedList;
};

class DoubleNode{
	int data;
	DoubleNode *next;
	DoubleNode *prev;
	//friend class DoublyLinkedList;
};

#endif /* SRC_NODE_H_ */
