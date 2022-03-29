#include"LinkedList.h"
#include<iostream>

LinkedList::LinkedList(){}
LinkedList::~LinkedList(){}

Node* LinkedList::at(int n) {
	if (n == 0) {
		return startNode;
	}
	else if (n < size) {
		std::cout << "out of range\n";
	}
	else {

		return at(n - 1)->next;
	}
	
}

void LinkedList::add(int valueP) {
	Node* temp = new Node(valueP, nullptr);
	if (size <= 0) {
		startNode = temp;
		std::cout << "le noeud de depart a bien etait ajouter\n";
		size++;
	}
	else
	{
		at(size - 1)->next = temp;
		std::cout << "un noeud a bien etait ajouter\n";
		size++;
	}
}

void LinkedList::insert(int valueP, int n) {
	Node* temp = new Node(valueP, at(n - 1)->next);

}

void LinkedList::display(int n){
	Node* temp = at(n);
	std::cout << temp->value << " " << temp->next << "la valeur et l'adresse du noeud\n";

}