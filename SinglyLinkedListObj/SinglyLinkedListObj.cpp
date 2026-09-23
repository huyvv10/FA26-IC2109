#include <iostream>
#include <string>
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
		
		void addFirst(Car x){
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}
		
		void display(){
			if (isEmpty()) return;
			Node *cur=head;
			while (cur!=nullptr){
				cur->info.displayCar();
				cur=cur->next;
			}
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
		}
};

int main(){
	SinglyLinkedList myList;
	myList.addFirst(Car(1,"Toyota camry 2.0", 55000.5));
	myList.addFirst(Car(2,"Kia morning Xls", 25000.8));
	myList.addFirst(Car(3,"Mazda CX5", 45000.2));
	myList.addFirst(Car(4,"Phantom ghost", 255000.8));
	myList.addFirst(Car(5,"Toyota vios", 28500.0));
	myList.display2();

	return 0;
}
