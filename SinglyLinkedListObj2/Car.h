#pragma once
#include <string>

class Car{
	public:
		int 	id;
		std::string 	name;
		double 	price;
		
		Car();		
		Car (int _id, std::string _name, double _price);		
		void displayCar();		
		void displayCar2();
};