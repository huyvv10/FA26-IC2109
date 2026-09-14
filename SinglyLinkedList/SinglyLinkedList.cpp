#include <iostream>

using namespace std;
class Node {
	public:
		int info;
		Node *next;
		Node(int _info) {
			this->info=_info;
			this->next=nullptr;
		}
};

class SinglyLinkedList {
	private:
		Node *head, *tail;
	public:

		SinglyLinkedList() {
			head=tail=nullptr;
		}

		~SinglyLinkedList() {}

		bool isEmpty() {
			return head==nullptr;
		}

		//Insert x at the begining of the list
		void addFirst(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}

		//Insert x to the last of the list
		void addLast(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				tail->next=newNode;
				tail=newNode;
			}
		}

		void display() {
			Node *cur=head;
			while (cur!=nullptr) {
				cout<<cur->info<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}

		//Return number of nodes are existing in the list
		int countNodes() {
			int count=0;
			Node *cur=head;
			while (cur!=nullptr) {
				count++;
				cur=cur->next;
			}
			return count;
		}
		
		//Insert x into the position x within the list
		void insertAtPos(int x, int pos){
			int n = countNodes();
			if (pos<0 || pos>n) return;
			if (pos==0) {addFirst(x); return;}
			if (pos==n) {addLast(x); return;}
			int i=0;
			Node *cur=head;
			while (i+1!=pos){
				i++;
				cur=cur->next;
			}
			Node *newNode = new Node(x);
			newNode->next=cur->next;
			cur->next=newNode;
		}
		
		//Return the maximum value within the list
		int getMax(){
			int max=head->info;
			Node *cur=head->next;
			while (cur!=nullptr){
				if (cur->info>max) max = cur->info;
				cur=cur->next;	
			}
			return max;
		}
		
		//Return the minimum value within the list
		int getMin(){
			int min=head->info;
			Node *cur=head->next;
			while (cur!=nullptr){
				if (cur->info<min) min = cur->info;
				cur=cur->next;	
			}
			return min;
		}
};

int main() {
	SinglyLinkedList myList;
	myList.addFirst(8);
	myList.addFirst(4);
	myList.addFirst(9);
	myList.addFirst(6);
	myList.display();
	myList.addLast(3);
	myList.addLast(5);
	myList.addLast(9);
	myList.display();
	cout<<"Number of nodes: "<<myList.countNodes()<<endl;
	int x, pos;
	cout<<"Input value x = "; cin>>x;
	cout<<"Input position to add pos = "; cin>>pos;
	myList.insertAtPos(x, pos);
	myList.display();	
	cout<<"The maximum value: "<<myList.getMax()<<endl;
	cout<<"The minimum value: "<<myList.getMin()<<endl;
	
}