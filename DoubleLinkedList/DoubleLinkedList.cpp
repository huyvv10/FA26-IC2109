#include <iostream>

using namespace std;

class Node{
	public:
		int info;
		Node *next, *prev;
		Node(int x): info(x), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList{
	private:
		Node *head, *tail;
	public:
		DoubleLinkedList(): head(nullptr), tail(nullptr){}
		~DoubleLinkedList(){}
		
		bool isEmpty(){
			return head==nullptr;
		}
		
		void addFirst(int x){
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->next=head;
				head->prev=newNode;
				head=newNode;
			}
		}
		
		void addLast(int x){
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				tail->next=newNode;
				newNode->prev=tail;
				tail=newNode;
			}				
		}
		
		//Return number of nodes within the list
		int countNodes(){
			int count=0;
			Node *cur=head;
			while (cur!=nullptr){
				count++;
				cur=cur->next;
			}
			return count;
		}
		
		void display(){
			Node *cur=head;
			while (cur!=nullptr){
				cout<<cur->info<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}
};

int main(){
	DoubleLinkedList myList;
	myList.addFirst(6);
	myList.addFirst(2);
	myList.addFirst(9);
	myList.addFirst(8);
	myList.display();
	myList.addLast(7);
	myList.addLast(4);
	myList.addLast(2);
	myList.addLast(9);
	myList.display();
	cout<<"Number of nodes: "<<myList.countNodes()<<endl;
	return 0;
}
