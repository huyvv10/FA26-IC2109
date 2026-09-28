#include <stdio.h>
#include "Node.h"
#include "Car.h"

//Node::Node(Car x) {
//	this->info=x;
//	this->next=nullptr;
//}
Node::Node(Car x) 
	: info(x), next(nullptr){} 