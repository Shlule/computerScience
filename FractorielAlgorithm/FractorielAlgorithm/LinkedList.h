#pragma once
#include<vector>

struct Node {
	Node();
	Node(int valueP,Node* nextP): value(valueP), next(nextP){}
	~Node() {
		if (next != nullptr) {
			delete next;
		}
	}
	int value;
	Node* next;
};

class LinkedList {

public:
	LinkedList();
	~LinkedList();
	//function at return nieme element in linkedlist
	Node* at(int n);
	//function that add element at the end of the linked list
	void add(int valueP);
	//function that remove the the last element of linked list
	void remove();
	//function that remove the nieme element of the linked list
	void remove(int n);
	//function that add element at the nieme position of the linked list
	void insert(int valueP, int n);
	//function that display node at nieme index
	void display(int n);

	//function that display linked list;
	void displayList();

	//function tha bubble sorting in croissant order
	void bubbleSort();

	//function that quick sorting the linked list
	void quicksort();

	

private:
	Node* startNode;
	int size;
};