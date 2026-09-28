#include <iostream>
#include <string>
#include <iomanip>
#include "Car.h"

Car::Car():id(0), name(""), price(0.0) {}

//Car::Car(){
//	this->id=0;
//	this->name="";
//	this->price=0.0;
//}

Car::Car (int _id, std::string _name, double _price)
	:id(_id), name(_name), price(_price) {}

void Car::displayCar() {
	std::cout<<"("<<id<<","<<name<<","<<std::fixed<<std::setprecision(2)<<price<<")";
}

void Car::displayCar2() {
	std::cout<<std::left<<
	    std::setw(5)<<id<<
	    std::setw(25)<<name<<
	    std::right<<std::setw(10)<<
	    std::fixed<<std::setprecision(2)<<price<<std::endl;
}