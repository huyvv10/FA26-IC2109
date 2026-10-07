#include <iostream>
#include <queue>

using namespace std;
class Node {
	public:
		int data;
		Node *left, *right;
		Node ():
			data(0), left(nullptr), right(nullptr) {}
		Node (int _data)
			: data(_data), left(nullptr), right(nullptr) {}
};

class BSTree {
	public:
		Node *root;

		BSTree() : root(nullptr) {}
		~BSTree() {}

		bool isEmpty() {
			return root==nullptr;
		}

		void addNode(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				root = newNode;
				return;
			}
			Node *cur=root;
			while (cur!=nullptr) {
				if (x < cur->data) {
					if (cur->left==nullptr) {
						cur->left=newNode;
						return;
					} else
						cur=cur->left;
				} else if (x > cur->data) {
					if (cur->right==nullptr) {
						cur->right=newNode;
						return;
					} else
						cur=cur->right;
				} else {
					cout<<x<<" already existed."<<endl;
				}
			}
		}

		void visit(Node *p) {
			if (isEmpty()) return;
			cout<<p->data<<" ";
		}

		void preOrder(Node *root) {
			if (root==nullptr) return;
			visit(root);				//Visit root
			if (root->left!=nullptr)	//Visit left child
				preOrder(root->left);
			if (root->right!=nullptr)	//Visit right child
				preOrder(root->right);
		}
		void inOrder(Node *root) {
			if (root==nullptr) return;
			if (root->left!=nullptr)
				inOrder(root->left);	//Visit left child
			visit(root);				//Visit root
			if (root->right!=nullptr)
				inOrder(root->right);	//Visit right child
		}
		void postOrder(Node *root) {
			if (root==nullptr) return;
			if (root->left!=nullptr)
				postOrder(root->left);	//Visit left child
			if (root->right!=nullptr)
				postOrder(root->right);	//Visit right child
			visit(root);				//Visit root
		}
		
		//Level traversal
		void bread_first_traversal(Node *root){
			queue<Node *> myQ;
			myQ.push(root);				//enqueue
			while (!myQ.empty()){
				Node *p = myQ.front();
				visit(p);
				myQ.pop();				//dequeue
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);	
			}
		}
		
		//Return number of nodes within the tree
		int countNodes(){
			int count=0;
			queue<Node *> myQ;
			myQ.push(root);				//enqueue
			while (!myQ.empty()){
				Node *p = myQ.front();
				count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);	
			}	
			return count;		
		}
		
		int countNodesRecursion(Node *root){
			int c=0, l=0, r=0;
			if (root==nullptr) return 0;
			c++;
			if (root->left!=nullptr)
				l = countNodesRecursion(root->left);
			if (root->right!=nullptr)
				r = countNodesRecursion(root->right);
			return c + l + r;		
		}
		
		int countInternalNodes(Node *root){
			return 0;
		}
		
		int countExternalNodes(Node *root){
			return 0;
		}
};
int main() {
	BSTree myBST;
	myBST.addNode(15);
	myBST.addNode(7);
	myBST.addNode(19);
	myBST.addNode(6);
	myBST.addNode(11);
	myBST.addNode(21);
	myBST.addNode(4);
	myBST.addNode(5);
	myBST.addNode(9);
	myBST.addNode(17);
	myBST.addNode(20);
	myBST.addNode(25);
	myBST.addNode(14);
	cout<<"---PreOrder Traversal---"<<endl;
	myBST.preOrder(myBST.root);
	cout<<"\n---InOrder Traversal---"<<endl;
	myBST.inOrder(myBST.root); 
	cout<<"\n---PostOrder Traversal---"<<endl;
	myBST.postOrder(myBST.root);
	cout<<"\n---Breadth First Traversal---"<<endl;
	myBST.bread_first_traversal(myBST.root);
	cout<<"\nNumber of nodes: "<<myBST.countNodes()<<endl;
	cout<<"Number of nodes Recursion: "<<myBST.countNodesRecursion(myBST.root)<<endl;
	
	return 0;
}
