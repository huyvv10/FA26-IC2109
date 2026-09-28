#pragma once
#include "Car.h"
#include "Node.h"

class SinglyLinkedList{
	private:
		Node *head, *tail;
	public:
		SinglyLinkedList();
		~SinglyLinkedList();
		
		bool isEmpty();		
		bool containX(std::string str, char c);
		
		//Do nothing if car name containing character x (ignore case) or price<$10000
		//Otherwise insert car x into the begining of the list		
		void addFirst(Car x);		
		void addLast(Car x);
		
		//Display cars with price in the range [50000,100000] inclusive
		void diplayCarByPriceInRange(int p1, int p2);
		//Remove a car which is the cheapest.
		
		//Insert a new car(10, "Huyndai Santafe 2.0", 47000) infront of the most expensive car.
	
		void display();
		void display2();
};