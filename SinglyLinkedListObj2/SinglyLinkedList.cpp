#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "SinglyLinkedList.h"
#include "Car.h"
#include "Node.h"

SinglyLinkedList::SinglyLinkedList()
	: head(nullptr), tail(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
}

bool SinglyLinkedList::isEmpty() {
	return head==nullptr;
}
bool SinglyLinkedList::containX(std::string str, char c) {
	int n = str.length();
	for (int i=0; i<n; i++)
		if (tolower(str[i])==tolower(c)) return true;
	return false;
}
//Do nothing if car name containing character x (ignore case) or price<$10000
//Otherwise insert car x into the begining of the list
void SinglyLinkedList::addFirst(Car x) {
	if (containX(x.name, 'X') || x.price<10000) return;

	Node *newNode = new Node(x);
	if (isEmpty()) {
		head=tail=newNode;
	} else {
		newNode->next=head;
		head=newNode;
	}
}
void SinglyLinkedList::addLast(Car x) {
	if (containX(x.name, 'X')) return;
	Node *newNode = new Node(x);
	if (isEmpty()) {
		head=tail=newNode;
	} else {
		tail->next=newNode;
		tail=newNode;
	}
}
//Display cars with price in the range [50000,100000] inclusive
void SinglyLinkedList::diplayCarByPriceInRange(int p1, int p2) {
	if (isEmpty()) return;
	Node *cur=head;
	std::cout<<std::left<<std::setw(5)<<"ID"<<std::setw(25)<<"NAME"<<std::right<<std::setw(10)<<"PRICE"<<std::endl;
	std::cout<<std::left<<std::setw(5)<<"--"<<std::setw(25)<<"----"<<std::right<<std::setw(10)<<"-----"<<std::endl;
	while (cur!=nullptr) {
		if (cur->info.price>=p1 && cur->info.price<=p2)
			cur->info.displayCar2();
		cur=cur->next;
	}
	std::cout<<std::endl;
}
//Remove a car which is the cheapest.

//Insert a new car(10, "Huyndai Santafe 2.0", 47000) infront of the most expensive car.

void SinglyLinkedList::display() {
	if (isEmpty()) return;
	Node *cur=head;
	while (cur!=nullptr) {
		cur->info.displayCar();
		cur=cur->next;
	}
	std::cout<<std::endl;
}
void SinglyLinkedList::display2() {
	if (isEmpty()) return;
	Node *cur=head;
	std::cout<<std::left<<std::setw(5)<<"ID"<<std::setw(25)<<"NAME"<<std::right<<std::setw(10)<<"PRICE"<<std::endl;
	std::cout<<std::left<<std::setw(5)<<"--"<<std::setw(25)<<"----"<<std::right<<std::setw(10)<<"-----"<<std::endl;
	while (cur!=nullptr) {
		cur->info.displayCar2();
		cur=cur->next;
	}
	std::cout<<std::endl;
}