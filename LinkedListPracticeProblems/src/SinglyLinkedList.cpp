#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList(){
 head=NULL;
}
void SinglyLinkedList::insertAtEnd(int data){
	SingleNode *node = new SingleNode();
	node->data = data;
	if(head==NULL){
		head = node;
		node -> next = NULL;
	}
	else{
		SingleNode *tmp = head;
		while(tmp->next != NULL){
			tmp=tmp->next;
		}
		tmp->next = node;
		node->next = NULL;
	}
}

void SinglyLinkedList::printSinglyLinkedList(SinglyLinkedList sl){
	SingleNode *tmp = head;
	if(head == NULL){
		cout<<"List empty"<<endl;
		return;
	}
	cout<<endl<<"List is:"<<endl;
	while(tmp != NULL){
		cout<<tmp->data<<" -> ";
		tmp = tmp -> next;
	}
}
//Reverse Singly Linked List
void SinglyLinkedList::reverseSinglyLinkedList(SinglyLinkedList l){
	if(head == NULL || head->next == NULL){
		return;
	}
	else{
		SingleNode *tmp = head;
		SingleNode *prev = NULL;
		SingleNode *next;
		while(tmp != NULL){
			next = tmp -> next;
			tmp -> next = prev;
			prev = tmp;
			tmp = next;
		}
		head = prev;
	}
}
