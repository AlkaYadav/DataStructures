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

void SinglyLinkedList::insertSortedLinkedList(int data){
	SingleNode *node = new SingleNode();
	node->data = data;
	if(head==NULL){
			head = node;
			node -> next = NULL;
		}
	else{
		if(data<=head->data){
			node->next=head;
			head=node;
			//case 1:insert at head
			return;
		}
		SingleNode *tmp = head;
		SingleNode *next = NULL;
		while(true){
			//case 2:insert at end
			if(tmp->next == NULL){
				tmp->next=node;
				node->next=NULL;
				break;
			}
			//case 3:insert in between
			if(  tmp->data<=data && data< tmp->next->data){
				next = tmp->next;
				tmp->next=node;
				node->next=next;
				break;
			}
			tmp=tmp->next;
}
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
	if(head_node->next == NULL){
		head=head_node;
		return;
	}
	else{
		reverseSinglyLinkedList_recursiveHelper(head_node->next);
		head_node->next->next = head_node;
		head_node->next=NULL;
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

void SinglyLinkedList::createDummyList(){
	int nodes,data;
	cout<<"Enter the number of nodes"<<endl;
	cin>>nodes;
	while(nodes){
		cout<<"Enter data"<<endl;
		cin>>data;
		insertAtEnd(data);
		nodes--;
	}
	//Point the last node to head to create a loop
	SingleNode *tmp=head;
	while(tmp->next){
		tmp=tmp->next;
	}
	tmp->next=head;
}
//Check if a loop exists in Singly Linked List
bool SinglyLinkedList::checkIfLoopInList(){
	SingleNode *slowptr = head;
	SingleNode *fastptr = head;
	while(slowptr && fastptr){
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;
		if(slowptr == fastptr){
			return true;
		}
	}
	return false;
}

//Delete a linked list
void SinglyLinkedList::deleteLinkedList(){
	SingleNode *tmp=head;
	SingleNode *deletenode;
	while(tmp){
		deletenode=tmp;
		tmp=tmp->next;
		free(deletenode);
	}
	head=NULL;
}

//Print Nth node from end in a singly linked list
/*
 * Maintain two pointers – reference pointer and main pointer.
 *  Initialize both reference and main pointers to head.
 *  First move reference pointer to n nodes from head.
 *  Now move both pointers one by one until reference pointer reaches end.
 * Now main pointer will point to nth node from the end. Return main pointer.
 */
void SinglyLinkedList::printNthNodeFromEndLinkedList(int n){
	SingleNode *refptr=head;
	SingleNode *mainptr=head;
	int count =1;
	if(n>lengthOfLinkedList() || n<=0){
		cout<<"Number is not correct.Must be from 1 to length "<<endl;
		return;
	}
	while(count <= n){
		refptr = refptr->next;
		count ++;
	}
	while(refptr){
		refptr = refptr->next;
		mainptr = mainptr->next;
	}
	cout<<"Data is ::"<<mainptr->data;
}
