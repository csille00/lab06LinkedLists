#pragma once
#include <string>
#include "LinkedListInterface.h"
#include <iostream>
#include <sstream>


using namespace std;

template<class T>
class LinkedList: public LinkedListInterface<T>
{
private:
	struct Node {
		T item;
		Node* next;
		Node(const T& data_item, Node* next_ptr = NULL):
			item(data_item), next(next_ptr){}
};
Node* head;
int num_items;

public:
	int find(const T& itemToFind) {
		int counter = 0;
		for(Node *ptr = head; ptr != NULL; ptr = ptr->next){
			if (ptr->item == itemToFind) return counter;
			counter++;
			
		}
		return -1;
	}

	LinkedList(void) {
		head = NULL;
		num_items = 0;
		cout << "in constructor" << endl;
	};
	 ~LinkedList(void) {
		cout << "in destructor" << endl;
		clear();
	}

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	 void insertHead(T value) {
		cout << "In insert Head" << endl;
		 if(find(value) != -1)
			 return;
		 
		 head = new Node(value, head);
		 num_items++;
		}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	 void insertTail(T value){
	 	cout << "In insertTail" << endl;
		 if(find(value) != -1)
			 return;
		 
		if(head == NULL){
			insertHead(value);
			num_items++;
		}
		else{ 
		 Node* ptr;
	 	 for(ptr = head; ptr->next != NULL; ptr = ptr->next);
		 
		 ptr->next = new Node(value);

		 num_items++;
		}
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	 void insertAfter(T value, T insertionNode){
		 if(find(insertionNode) != -1){
			int index = find(value);
		 	if(index == -1){
		 		Node* ptr = head;
		 		for(int i =0; i <= index + 1; i++){
			 		ptr = ptr->next; //increment pointer until it finds the value
		 		}
		 		Node *temp = ptr->next;
		 
		 		ptr->next = new Node(value, temp);
				num_items++;
			 }
		 }
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	 void remove(T value){
		cout << "In remove" << endl;
		int index = find(value);
		if(index >= num_items || index == -1) {
  		throw std::out_of_range("remove Error");
		}
		if(index == 0) {
  		Node *current = head;
  		head = head->next;
  		delete current;
		} else {
  		Node *ptr = head;
  		for(int i = 0; i < index; i++) {
    		if(i == (index-1)) { // Delete after this
      		Node *current = ptr->next;
      		ptr->next = ptr->next->next;
      		delete current;
      		num_items--;
    		}else {
      		ptr = ptr->next;
		    }
		  }
		}
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	 void clear() {
		cout << "clear" << endl;
		while(head != NULL){
			Node *current = head;
			head = head->next;
			delete current;
			num_items--;
		}

	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	 T at(int index){
		cout << "In at " << endl;
		 if(index < 0 || index >= num_items){
			 throw out_of_range("index out of range");
		 }
		 Node* ptr = head;
		 		for(int i =0; i < index; i++){
			 		ptr = ptr->next; //increment pointer until it finds the value
		 		}
		return ptr->item ;
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	 int size(){
		cout << "in size" << endl;
		return num_items;
	}

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	 string toString(){
		cout << "in string" << endl;
		 stringstream ss;
		 // cout << "did i make it this far" << endl;
			 for(Node *ptr = head; ptr != NULL; ptr = ptr->next){

			// cout << "what about here?" << endl;
			 if(ptr->next == NULL){ 
			 	ss << ptr ->item; 
			 }
			 else if(num_items == 1){
				ss << ptr ->item;	
				// cout << "did i make it this far" << endl;
			 }
			 else {
				 ss << ptr->item << " ";
			 }
		 }
		 
		return ss.str();
		// }
	}

};
