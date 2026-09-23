#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

class Car{
	public:
		int id;
		string name;
		double price;
		Car():id(0), name(""), price(0.0){}
		Car (int _id, string _name, double _price):
			id(_id), name(_name), price(_price){}
		
		void displayCar(){
			cout<<"("<<id<<","<<name<<","<<fixed<<setprecision(2)<<price<<")";
		}	
		
		void displayCar2(){
			cout<<left<<
			setw(5)<<id<<
			setw(25)<<name<<
			right<<setw(10)<<
			fixed<<setprecision(2)<<price<<endl;
		}	
};

class Node{
	public:
		Car info;
		Node *next;
		Node(Car x){
			this->info=x;
			this->next=nullptr;
		}
};

class SinglyLinkedList{
	private:
		Node *head, *tail;
	public:
		SinglyLinkedList(){
			head=tail=nullptr;
		}	
		~SinglyLinkedList(){}
		
		bool isEmpty(){
			return head==nullptr;
		}
		
		bool containX(string str, char c){
			int n = str.length();
			for (int i=0; i<n; i++)
				if (tolower(str[i])==tolower(c)) return true;			
			return false;	
		}
		
		//Do nothing if car name containing character x (ignore case) or price<$10000
		//Otherwise insert car x into the begining of the list		
		void addFirst(Car x){
			if (containX(x.name, 'X') || x.price<10000) return;	
			
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}
		
		void addLast(Car x){
			if (containX(x.name, 'X')) return;	
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				tail->next=newNode;
				tail=newNode;
			}
		}
		
		//Display cars with price in the range [50000,100000] inclusive
		void diplayCarByPriceInRange(int p1, int p2){
			if (isEmpty()) return;
			Node *cur=head;
			cout<<left<<setw(5)<<"ID"<<setw(25)<<"NAME"<<right<<setw(10)<<"PRICE"<<endl;			
			cout<<left<<setw(5)<<"--"<<setw(25)<<"----"<<right<<setw(10)<<"-----"<<endl;			
			while (cur!=nullptr){
				if (cur->info.price>=p1 && cur->info.price<=p2)
					cur->info.displayCar2();
				cur=cur->next;
			}
			cout<<endl;			
		}	
		
		//Remove a car which is the cheapest.
		
		//Insert a new car(10, "Huyndai Santafe 2.0", 47000) infront of the most expensive car.
		
		void display(){
			if (isEmpty()) return;
			Node *cur=head;
			while (cur!=nullptr){
				cur->info.displayCar();
				cur=cur->next;
			}
			cout<<endl;
		}
		void display2(){
			if (isEmpty()) return;
			Node *cur=head;
			cout<<left<<setw(5)<<"ID"<<setw(25)<<"NAME"<<right<<setw(10)<<"PRICE"<<endl;			
			cout<<left<<setw(5)<<"--"<<setw(25)<<"----"<<right<<setw(10)<<"-----"<<endl;			
			while (cur!=nullptr){
				cur->info.displayCar2();
				cur=cur->next;
			}
			cout<<endl;
		}
};

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
