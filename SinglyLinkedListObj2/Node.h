#pragma once
#include "Car.h"

class Node{
	public:
		Car 	info;
		Node 	*next;
		
		Node(Car x);
};