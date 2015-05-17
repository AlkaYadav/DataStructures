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

bool SinglyLinkedList::checkIfListPalindrome(){
	SinglyLinkedList reversed;
	SingleNode *tmp = head;

	while(tmp != NULL){
		reversed.insertAtEnd(tmp -> data);
		tmp = tmp -> next;
	}
	reversed.printSinglyLinkedList();
	reversed.reverseSinglyLinkedList();
	reversed.printSinglyLinkedList();
	SingleNode *tmp1 = head;
	SingleNode *tmp2 = reversed.head;
	while(tmp1!=NULL){
		if(tmp1->data != tmp2->data)
			return false;
		else{
			tmp1 = tmp1 -> next;
			tmp2 = tmp2 ->next;
		}
	}
	return true;
}

bool SinglyLinkedList::checkIfListPalindrome_usingStack(){
	stack <int> s;
	SingleNode *tmp = head;
	while(tmp){
		s.push(tmp->data);
		tmp = tmp->next;
	}
	tmp = head;
	while(tmp){

		if(tmp->data != s.top()){
			return false;
		}
		else{
			s.pop();
			tmp = tmp->next;
		}
	}
	return true;
}
void SinglyLinkedList::printSinglyLinkedList(){
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
void SinglyLinkedList::reverseSinglyLinkedList(){
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

//Reverse singly linked list using recursion
void SinglyLinkedList::reverseSinglyLinkedList_recursive(){
	reverseSinglyLinkedList_recursiveHelper(head);
}

void SinglyLinkedList::reverseSinglyLinkedList_recursiveHelper(SingleNode *head_node){
	if(head_node == NULL){
		return;
	}
	else{
		SingleNode *prev=NULL;
		SingleNode *next;
		prev = head_node;
		next = head_node ->next;
		head_node -> next = prev;
		cout<<"Previous node is:"<<prev->data;
		cout<<"Next node is:"<<next ->data;
		reverseSinglyLinkedList_recursiveHelper(next);
		head = prev;
	}
}


int SinglyLinkedList::lengthOfLinkedList(){
	int length =0;
	SingleNode *tmp = head;
	while(tmp){
		length ++;
		tmp=tmp->next;
	}
	return length;
}

bool SinglyLinkedList::checkIfListPalindrome_usingNoStorage(){
	int length=lengthOfLinkedList();
	int middle,index_tmp;
	int index=0;
	if(length%2==0){
		middle=length/2;
	}
	else{
		middle=length/2+1;
	}
	SingleNode *tmp = head;
	SingleNode *prev =NULL;
	SingleNode *next;
	//Go to second half starting location
	while(index != middle){
		prev=tmp;
		tmp =tmp->next;
		index++;
	}
	SingleNode *end_firsthalf=prev;//Needed to recover the original list
	//Reverse second half of linked list
	while(tmp != NULL){
				next = tmp -> next;
				tmp -> next = prev;
				prev = tmp;
				tmp = next;
			}
	SingleNode *start_secondhalf=prev;//Needed to recover the original list
 //Now the second half of the list is reversed.
	SingleNode *index_firsthalf =head;
	SingleNode *index_secondhalf =prev;
	index=0;
	if(length%2==0){
		index_tmp=middle;
	}
	else{
		index_tmp=middle-1;
	}
	int flag=1;
	while(index<index_tmp){
		if(index_firsthalf->data != index_secondhalf->data){
			flag=0;
			break;
		}
		index_firsthalf=index_firsthalf->next;
		index_secondhalf=index_secondhalf->next;
		index++;
	}
	SingleNode *next_recoverlist;
	SingleNode *prev_recoverlist=NULL;
	int index_recoverlist=0;
	while(index_recoverlist!=length/2){
		next_recoverlist=start_secondhalf->next;
		start_secondhalf->next = prev_recoverlist;
		prev_recoverlist=start_secondhalf;
		start_secondhalf=next_recoverlist;
		index_recoverlist=index_recoverlist+1;
	}
	//Reverse the list again to undo the changes
   if(flag==0)
	return false;
   else
	   return true;
}
