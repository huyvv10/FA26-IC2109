#include <iostream>
#include <queue>

using namespace std;

class Node{
	public:
		int data, height;
		Node *left, *right;
		Node(int _data):
			data(_data), height(1), left(nullptr), right(nullptr){}	
};

class AVLTree{
	public:
		Node *root;
		AVLTree(){
			this->root=nullptr;
		}
		
		~AVLTree(){}
		
		bool isEmpty(){
			return root==nullptr;
		} 
		
		int getHeight(Node *p){
			if (p==nullptr) return 0;
			return p->height;
		}
		
		int getBalance(Node *p){
			if (p==nullptr) return 0;
			return getHeight(p->left) - getHeight(p->right);
		}
		
		Node *rightRotate(Node *p){
			Node *k = p->left;
			p->left = k->right;
			k->right= p;
			
			p->height = max(getHeight(p->left), getHeight(p->right))+1;
			k->height = max(getHeight(k->left), getHeight(k->right))+1;
			return k;
		}
		
		Node *leftRotate(Node *p){
			Node* k = p->right;
			p->right= k->left;
			k->left = p;
			
			p->height = max(getHeight(p->left), getHeight(p->right))+1;
			k->height = max(getHeight(k->left), getHeight(k->right))+1;
			return k;			
		}
		
		Node* insertAVLNode(Node* root, int x){
			Node* newNode = new Node(x);
			if (root==nullptr) return newNode;
			if (x < root->data){
				root->left = insertAVLNode(root->left, x);
			} else if (x > root->data){
				root->right = insertAVLNode(root->right, x);
			} else {
				return root;
			}
			//Update height
			root->height = max(getHeight(root->left), getHeight(root->right))+1;
			//Calculate balance factor
			int balanceFactor = getBalance(root);
			//Case 1:
			if (balanceFactor>1 && x < root->left->data)
				return rightRotate(root);
			//Case 2:
			if (balanceFactor>1 && x > root->left->data){
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
			//Case 3: 
			if (balanceFactor<-1 && x > root->right->data)
				return leftRotate(root);
			//Case 4:
			if (balanceFactor<-1 && x < root->right->data){
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}	
			return root;
		}
		
		void visit(Node *p) {
			if (isEmpty()) return;
			cout<<p->data<<" ";
		}
				
		//Level traversal
		void bread_first_traversal(Node *root) {
			queue<Node *> myQ;
			myQ.push(root);				//enqueue
			while (!myQ.empty()) {
				Node *p = myQ.front();
				visit(p);
				myQ.pop();				//dequeue
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);
			}
		}
		
};

int main(){
	AVLTree myAVL;
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 20);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 6);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 9);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 17);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 30);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 35);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 40);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 25);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 27);
	myAVL.bread_first_traversal(myAVL.root);
	cout<<endl;
	return 0;
}
