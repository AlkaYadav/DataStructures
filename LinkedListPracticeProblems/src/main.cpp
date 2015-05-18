#include"SinglyLinkedList.h"

int main(){
	SinglyLinkedList singlyLinkedList;
	SinglyLinkedList dummyLinkedList;
	SinglyLinkedList sortedLinkedList;
	int choice,num,data;
	char response;
	do{
		cout<<"1. Create a singly linked list"<<endl;
		cout<<"2. Reverse singly linked list --Iterative--"<<endl;
		cout<<"3. Reverse singly linked list--Recursive--"<<endl;
		cout<<"4. Check if list is palindrome--"<<endl;
		cout<<"5. Check if list is palindrome using stack--"<<endl;
		cout<<"6. Check if list is palindrome using no storage--"<<endl;
		cout<<"7. Print Singly linked list"<<endl;
		cout<<"8. Check if a loop exist in Singly linked list"<<endl;
		cout<<"9. Create a sorted singly linked list"<<endl;
		cout<<"10. Delete singly linked list"<<endl;
		cout<<"Enter one of the choices"<<endl;
		cin>>choice;
		switch(choice){
		case 1:
			cout<<"Enter the number of nodes to insert at end"<<endl;
			cin>>num;
			for(int i=0;i<num;i++){
				cout<<"Enter data for node"<<endl;
				cin>>data;
				singlyLinkedList.insertAtEnd(data);
			}
			singlyLinkedList.printSinglyLinkedList();
			break;
		case 2:
			singlyLinkedList.reverseSinglyLinkedList();
			cout<<endl<<"After reversal"<<endl;
			singlyLinkedList.printSinglyLinkedList();
			break;
		case 3:
			singlyLinkedList.reverseSinglyLinkedList_recursive();
			cout<<endl<<"After reversal"<<endl;
			singlyLinkedList.printSinglyLinkedList();
			break;
		case 4:
			cout<<"Checking if List is palindrome:"<<singlyLinkedList.checkIfListPalindrome()<<endl;
			break;
		case 5:
			cout<<"Checking if List is palindrome:"<<singlyLinkedList.checkIfListPalindrome_usingStack()<<endl;
			break;
		case 6:
			cout<<"Checking if List is palindrome:"<<singlyLinkedList.checkIfListPalindrome_usingNoStorage()<<endl;
			break;
		case 7:
			singlyLinkedList.printSinglyLinkedList();
			break;
		case 8:
			dummyLinkedList.createDummyList();
			cout<<"Loop exist is(Loop is present):"<<dummyLinkedList.checkIfLoopInList()<<endl;
			cout<<"Loop exist is(Loop is not present):"<<singlyLinkedList.checkIfLoopInList()<<endl;
			break;
		case 9:
			cout<<"Enter the number of nodes to insert in sorted manner"<<endl;
			cin>>num;
			for(int i=0;i<num;i++){
				cout<<"Enter data for node"<<endl;
				cin>>data;
				sortedLinkedList.insertSortedLinkedList(data);
			}
			sortedLinkedList.printSinglyLinkedList();
			break;
		case 10:
			singlyLinkedList.deleteLinkedList();
			break;
		}

		cout<<endl<<"Do you want to continue?Enter y or Y to continue"<<endl;
		cin>>response;
	}while(response=='y'|| response == 'Y');
	return 0;
}
