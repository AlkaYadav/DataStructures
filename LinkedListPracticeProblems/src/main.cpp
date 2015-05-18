#include"SinglyLinkedList.h"

int main(){
	SinglyLinkedList singlyLinkedList;
	SinglyLinkedList dummyLinkedList;
	SinglyLinkedList sortedLinkedList;
	SinglyLinkedList sortedLinkedList2;
	SinglyLinkedList mergedLinkedList;
	int choice,num,data,n;
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
		cout<<"11. Print nth node from end in singly linked list"<<endl;
		cout<<"12. Delete alternate nodes from a singly linked list"<<endl;
		cout<<"13. Pairwise swap elements in a singly linked list"<<endl;
		cout<<"14. Merge two sorted singly linked lists"<<endl;
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
		case 11:
			cout<<"Enter nth number"<<endl;
			cin>>n;
			singlyLinkedList.printNthNodeFromEndLinkedList(n);
			break;
		case 12:
			singlyLinkedList.deleteAlternateNodes();
			singlyLinkedList.printSinglyLinkedList();
			break;
		case 13:
			singlyLinkedList.pairwiseSwapElementsLinkedList();
			singlyLinkedList.printSinglyLinkedList();
			break;
		case 14:
			cout<<"Enter the number of nodes to insert in sorted manner"<<endl;
			cin>>num;
			for(int i=0;i<num;i++){
				cout<<"Enter data for node"<<endl;
				cin>>data;
				sortedLinkedList.insertSortedLinkedList(data);
			}
			sortedLinkedList.printSinglyLinkedList();

			cout<<"Enter the number of nodes to insert in sorted manner"<<endl;
			cin>>num;
			for(int i=0;i<num;i++){
				cout<<"Enter data for node"<<endl;
				cin>>data;
				sortedLinkedList2.insertSortedLinkedList(data);
			}
			sortedLinkedList2.printSinglyLinkedList();

			mergedLinkedList=singlyLinkedList.mergeTwoSortedLinkedList(sortedLinkedList,sortedLinkedList2);
			mergedLinkedList.printSinglyLinkedList();
			break;
		}

		cout<<endl<<"Do you want to continue?Enter y or Y to continue"<<endl;
		cin>>response;
	}while(response=='y'|| response == 'Y');
	return 0;
}
