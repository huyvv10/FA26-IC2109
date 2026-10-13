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
		~BSTree() {
			queue<Node *> myQ;
			myQ.push(root);				//enqueue
			while (!myQ.empty()) {
				Node *p = myQ.front();
				myQ.pop();				//dequeue
				Node *tmp=p;
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);
				delete tmp;
			}
		}

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

		//Return number of nodes within the tree
		int countNodes() {
			int count=0;
			queue<Node *> myQ;
			myQ.push(root);				//enqueue
			while (!myQ.empty()) {
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

		int countNodesRecursion(Node *root) {
			int c=0, l=0, r=0;
			if (root==nullptr) return 0;
			c++;
			if (root->left!=nullptr)
				l = countNodesRecursion(root->left);
			if (root->right!=nullptr)
				r = countNodesRecursion(root->right);
			return c + l + r;
		}

		int countInternalNodes(Node *root) {
			int count=0;
			queue<Node *> myQ;
			myQ.push(root);				//enqueue
			while (!myQ.empty()) {
				Node *p = myQ.front();
				if (p->left!=nullptr || p->right!=nullptr)
					count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);
			}
			return count;
		}

		//Count number of leaf nodes
		int countExternalNodes(Node *root) {
			int count=0;
			queue<Node *> myQ;
			myQ.push(root);				//enqueue
			while (!myQ.empty()) {
				Node *p = myQ.front();
				if (p->left==nullptr && p->right==nullptr)
					count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);
			}
			return count;
		}

		Node* findTheRightMostNode(Node* p) {
			if (p==nullptr) return nullptr;
			Node *cur=p->left;
			if (cur->right ==nullptr) return cur;
			while (cur->right!=nullptr) {
				cur=cur->right;
			}
			return cur;
		}

		Node* deleteByCopying(Node *root, int x) {
			if (root==nullptr) return nullptr;
			if (x < root->data) {
				root->left=deleteByCopying(root->left, x);
			} else if (x > root->data) {
				root->right=deleteByCopying(root->right, x);
			} else {
				//Case1: deleted node is a leaf node
				if (root->left==nullptr && root->right==nullptr) {
					delete root;
					return nullptr;
				}
				//Case2: has a left subtree
				if (root->right==nullptr) {
					Node *tmp = root->left;
					delete root;
					return tmp;
				}
				//Case3: has a right subtree
				if (root->left==nullptr) {
					Node* tmp = root->right;
					delete root;
					return tmp;
				}
				//Case4: has two children
				if (root->left!=nullptr && root->right!=nullptr) {
					Node* copyNode = findTheRightMostNode(root);
					root->data = copyNode->data;
					root->left = deleteByCopying(root->left, copyNode->data);
				}
			}
			return root;
		}

		Node* deleteByMerging(Node* root, int x) {
			if (root==nullptr) return nullptr;
			if (x < root->data) {
				root->left=deleteByMerging(root->left, x);
			} else if (x > root->data) {
				root->right=deleteByMerging(root->right, x);
			} else {
				//Case1: deleted node is a leaf node
				if (root->left==nullptr && root->right==nullptr) {
					delete root;
					return nullptr;
				}
				//Case2: has a left subtree
				if (root->right==nullptr) {
					Node *tmp = root->left;
					delete root;
					return tmp;
				}
				//Case3: has a right subtree
				if (root->left==nullptr) {
					Node* tmp = root->right;
					delete root;
					return tmp;
				}
				//Case4: has two children
				if (root->left!=nullptr && root->right!=nullptr) {
					Node* mergeNode = findTheRightMostNode(root);
					mergeNode->right = root->right;
					Node *tmp=root->left;
					delete root;
					return tmp;
				}
			}
			return root;
		}
		
		int countNodesOnlyHasALeftSubtree(Node *p){
			int count=0;
			if (p==nullptr) return count;
			queue<Node *> myQ;
			myQ.push(p);				//enqueue
			while (!myQ.empty()) {
				Node *cur = myQ.front();
				if (cur->left!=nullptr && cur->right==nullptr)
					count++;
				myQ.pop();				//dequeue
				if (cur->left!=nullptr)
					myQ.push(cur->left);
				if (cur->right!=nullptr)
					myQ.push(cur->right);
			}
			return count;
		}
		
		int countNodesOnlyHasARightSubtree(Node *p){
			int count=0;
			if (p==nullptr) return count;
			queue<Node *> myQ;
			myQ.push(p);				//enqueue
			while (!myQ.empty()) {
				Node *cur = myQ.front();
				if (cur->left==nullptr && cur->right!=nullptr)
					count++;
				myQ.pop();				//dequeue
				if (cur->left!=nullptr)
					myQ.push(cur->left);
				if (cur->right!=nullptr)
					myQ.push(cur->right);
			}
			return count;
		}
		
		int countNodesHaveTwoChildren(Node *p){
			int count=0;
			if (p==nullptr) return count;
			queue<Node *> myQ;
			myQ.push(p);				//enqueue
			while (!myQ.empty()) {
				Node *cur = myQ.front();
				if (cur->left!=nullptr && cur->right!=nullptr)
					count++;
				myQ.pop();				//dequeue
				if (cur->left!=nullptr)
					myQ.push(cur->left);
				if (cur->right!=nullptr)
					myQ.push(cur->right);
			}
			return count;
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
	cout<<"Number of internal nodes: "<<myBST.countInternalNodes(myBST.root)<<endl;
	cout<<"Number of external nodes: "<<myBST.countExternalNodes(myBST.root)<<endl;
//	cout<<"Delete by Copying"<<endl;
//	myBST.root = myBST.deleteByCopying(myBST.root, 6);
//	myBST.bread_first_traversal(myBST.root);
//	cout<<"Delete by Merging"<<endl;
//	myBST.root = myBST.deleteByMerging(myBST.root, 15);
//	myBST.bread_first_traversal(myBST.root);
	cout<<"Number of nodes which have a left child: "<<myBST.countNodesOnlyHasALeftSubtree(myBST.root)<<endl;
	cout<<"Number of nodes which have a right child: "<<myBST.countNodesOnlyHasARightSubtree(myBST.root)<<endl;
	cout<<"Number of nodes which have two children: "<<myBST.countNodesHaveTwoChildren(myBST.root)<<endl;
	return 0;
}
