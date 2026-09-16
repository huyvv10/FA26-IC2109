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

		//Deconstructor - Ham huy
		~SinglyLinkedList() {
			Node *cur=head;
			while (cur!=nullptr) {
				Node *tmp=cur;
				cur=cur->next;
				delete tmp;
			}
			head=tail=nullptr;
		}

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
		void insertAtPos(int x, int pos) {
			int n = countNodes();
			if (pos<0 || pos>n) return;
			if (pos==0) {
				addFirst(x);
				return;
			}
			if (pos==n) {
				addLast(x);
				return;
			}
			int i=0;
			Node *cur=head;
			while (i+1!=pos) {
				i++;
				cur=cur->next;
			}
			Node *newNode = new Node(x);
			newNode->next=cur->next;
			cur->next=newNode;
		}

		//Return the maximum value within the list
		int getMax() {
			int max=head->info;
			Node *cur=head->next;
			while (cur!=nullptr) {
				if (cur->info>max) max = cur->info;
				cur=cur->next;
			}
			return max;
		}

		//Return the minimum value within the list
		int getMin() {
			int min=head->info;
			Node *cur=head->next;
			while (cur!=nullptr) {
				if (cur->info<min) min = cur->info;
				cur=cur->next;
			}
			return min;
		}

		//Return a node at the position pos
		Node *getNodeAtPos(int pos) {
			int n=countNodes();
			if (pos<0 || pos>=n) return nullptr;
			int i=0;
			Node *cur=head;
			while (i!=pos) {
				i++;
				cur=cur->next;
			}
			return cur;
		}

		//Edit a node at position pos with new value as newX
		void editAtPos(int newX, int pos) {
			int n=countNodes();
			if (pos<0 || pos>=n) return;
			int i=0;
			Node *cur=head;
			while (i!=pos) {
				i++;
				cur=cur->next;
			}
			cur->info=newX;
		}
		
		//Delete a node at the begining of the list
		void removeFirst(){
			if (isEmpty()) return;
			if (head->next==nullptr){
				head=tail=nullptr; return;
			}
			Node *tmp=head;
			head=head->next;
			delete tmp;
		}
		
		//Delete a node at the last of the list
		void removeLast(){
			
		}
		
		//Delete a node at the position pos
		void removeAtPos(int pos){
			
		}
		
		//Delete all elements with value as x
		void removeAll(int x){
			
		}
};

void menu() {
	cout<<"\n----SinglyLinked List -----"<<endl;
	cout<<"1. Add first"<<endl;
	cout<<"2. Add last"<<endl;
	cout<<"3. Display list"<<endl;
	cout<<"4. Add at position"<<endl;
	cout<<"5. Get maximum value"<<endl;
	cout<<"6. Get minimum value"<<endl;
	cout<<"7. Get value at pos"<<endl;
	cout<<"8. Edit at pos"<<endl;
	cout<<"9. Remove first"<<endl;
	cout<<"0. Add first"<<endl;
	cout<<"Your selection: ";
}
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
	int x, pos, sel;
	do {
		menu();
//		cin.ignore();
		cin>>sel;
		switch(sel) {
			case 1:
				cout<<"Add first"<<endl;
				cout<<"Input value x = ";
				cin>>x;
				myList.addFirst(x);
				break;
			case 2:
				cout<<"Add last"<<endl;
				cout<<"Input value x = ";
				cin>>x;
				myList.addLast(x);
				break;
			case 3:
				myList.display();
				break;
			case 4:
				cout<<"Insert at postion pos"<<endl;
				cout<<"Input value x = ";
				cin>>x;
				cout<<"Input position to add pos = ";
				cin>>pos;
				myList.insertAtPos(x, pos);
				myList.display();
				break;
			case 5:
				cout<<"The maximum value: "<<myList.getMax()<<endl;
				break;
			case 6:
				cout<<"The minimum value: "<<myList.getMin()<<endl;
				break;
			case 7:
				cout<<"Get value at pos"<<endl;
				cout<<"Input position to add pos = "; cin>>pos;
				if (myList.getNodeAtPos(pos)!=nullptr)
					cout<<myList.getNodeAtPos(pos)->info<<endl;
				break;
			case 8:
				cout<<"Edit at postion pos"<<endl;
				cout<<"Input new value = "; cin>>x;
				cout<<"Input position to edit: "; cin>>pos;
				myList.editAtPos(x, pos);	
				myList.display();			
				break;
			case 9:
				cout<<"Remove first"<<endl;
				myList.removeFirst(); 
				myList.display();
				break;
			case 0:
				cout<<"Bye bye!"<<endl;
				break;
			default:
				cout<<"Invalid selection. Please select again!"<<endl;
		}
	} while (sel!=0);

}