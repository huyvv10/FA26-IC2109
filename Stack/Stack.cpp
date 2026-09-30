#include <iostream>
#include <string>

using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node (int x) {
			this->data=x;
			this->next=nullptr;
		}
};

class Stack {
	private:
		Node *head;
	public:
		Stack() {
			head=nullptr;
		}

		bool isEmpty() {
			return head==nullptr;
		}

		//Insert an element x into the top of Stack - addFirst
		void push(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}

		//Remove an element at the top of stack.
		void pop() {
			if (isEmpty()) {
				cout<<"Stack is empty."<<endl;
				return;
			}
			Node *tmp=head;
			head=head->next;
			delete tmp;
		}

		//Return the value of an element at the top of stack
		//Return -999 in case stack is empty.
		int top() {
			if (isEmpty()) return -999;
			return head->data;
		}

		void display() {
			Node *cur=head;
			while (cur!=nullptr) {
				cout<<cur->data<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}
};

string dec2bin(int n) {
	Stack myStk;
	while (n!=0) {
		int r = n%2;
		myStk.push(r);
		n=n/2;
	}
	string S="";
	while (!myStk.isEmpty()){
		S+=to_string(myStk.top());
		myStk.pop();
	}
	return S;
}

int main() {
	Stack myStk;
	myStk.push(8);
	myStk.push(2);
	myStk.push(7);
	myStk.push(9);
	myStk.push(4);
	myStk.push(3);
	myStk.display();
	cout<<dec2bin(21)<<endl;
	return 0;
}
