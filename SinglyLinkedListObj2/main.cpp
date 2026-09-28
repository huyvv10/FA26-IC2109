#include <iostream>
#include "SinglyLinkedList.h"
#include "Car.h"

using namespace std;

int main(){
	SinglyLinkedList myList;
	myList.addFirst(Car(1,"Toyota camry 2.0", 55000.5));
	myList.addFirst(Car(2,"Kia morning Xls", 25000.8));
	myList.addFirst(Car(3,"Mazda CX5", 45000.2));
	myList.addFirst(Car(4,"Phantom ghost", 255000.8));
	myList.addFirst(Car(5,"Toyota vios", 8000.0));
	myList.display2();
	myList.addLast(Car(6,"Toyota Cross", 40500.0));
	myList.addLast(Car(7,"Vinfast VF9", 85000.0));
	myList.addLast(Car(8,"Vinfast VF7", 39500.0));
	myList.addLast(Car(9,"Ford Escape", 37000.7));
	myList.display2();
	cout<<"Display with price in the range"<<endl;
	myList.diplayCarByPriceInRange(50000,100000);
	
	return 0;
}
