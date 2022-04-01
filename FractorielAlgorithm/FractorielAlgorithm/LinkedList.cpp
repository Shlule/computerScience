#include"LinkedList.h"
#include<iostream>

LinkedList::LinkedList(){}
LinkedList::~LinkedList(){}

Node* LinkedList::at(int n) {
	if (n == 0) {
		return startNode;
	}
	else if (n > size) {
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
	if(n ==0){
		
		Node* temp = new Node(valueP, startNode);
		startNode = temp;
		size++;
	}
	else {
		Node* temp = new Node(valueP, at(n - 1)->next);
		at(n - 1)->next = temp;
		size++;
	}
	
	

}
void LinkedList::remove() {
	if (size == 0) {
		std::cout << "linked list is empty nothing to remove\n";
	}
	else {
		Node* temp = at(size - 2)->next;
		at(size - 2)->next = nullptr;
		delete at(size-1);
		size--;
	}
}

void LinkedList::remove(int n) {
	if (size == 0) {
		std::cout << "linkedList is empty nothing to remove\n";
	}
	else if (n == size - 1) {
		remove();
	}
	else if (n == 0) {
		Node* temp = startNode->next;
		startNode->next = nullptr;
		delete startNode;
		startNode = temp;
		size--;
	}
	else {
		//je sauvegarde l'adrresse du noeud suivant dans un temporaire
		Node* temp = at(n)->next;
		// j'initialise la variable next a nullptre
		at(n)->next = nullptr;
		// je supprime le noeud
		delete at(n);
		// je relie relie les noeud maintenant adjacent
		at(n - 1)->next = temp;
		size--;
	}
}
void LinkedList::bubbleSort() {
	int good =0;
	while (good != size - 1) {
		good = 0;
		for (int i = 0; i < size - 1; i++) {
			if (at(i)->value > at(i + 1)->value) {
				int temp = at(i)->value;
				at(i)->value = at(i + 1)->value;
				at(i + 1)->value = temp;
			}
			else {
				good++;
			}
		}
	}
}

void LinkedList::quicksort() {
	Node* pivot = at(size - 1);
	for (int i = 0; i < size - 2; i++) {
		if (at(i)->value >= pivot->value) {
			int temp = at(i)->value;
			remove(i);
			add(temp);
		}
	}
}

void LinkedList::display(int n){
	Node* temp = at(n);
	std::cout << temp->value << " " << temp->next << " la valeur et l'adresse du noeud\n";

}

void LinkedList::displayList() {
	for (int i = 0; i <= size - 1; i++) {
		display(i);
	}
}