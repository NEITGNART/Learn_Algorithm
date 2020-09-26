#include <iostream>
#include <string>

using namespace std;

struct Node {

	int key;
	Node* left;
	Node* right;
	Node(int key) : key(key), left(0), right(0) {}
};

class BST {
	Node* root;
public:
	BST() = default;
	
	BST(Node *root) {
		this->root = root;
	}
	
	void Insert(int key) {
		
		Node* q = root;
		
		while (q) {

			if (q->key == key) return;
			
			if (key < q->key) {
				if (q->left == nullptr) {
					q->left = new Node(key);;
			//		cout << "Insert " << key << " successfully!\n";
					return;
				}
				q = q->left;
				continue;
			}
			if (key > q->key) {
				if (q->right == nullptr) {
					q->right = new Node(key);
				//	cout << "Insert " << key << " successfully!\n";
					return;
				}
				q = q->right;
				continue;
			}
		}
	}
	struct Trunk
	{
		Trunk* prev;
		string str;

		Trunk(Trunk* prev, string str)
		{
			this->prev = prev;
			this->str = str;
		}
	};

	// Helper function to print branches of the binary tree
	void showTrunks(Trunk* p)
	{
		if (p == nullptr)
			return;

		showTrunks(p->prev);

		cout << p->str;
	}

	// Recursive function to print binary tree
	// It uses inorder traversal
	void printTree(Node* root, Trunk* prev, bool isLeft)
	{
		if (root == nullptr)
			return;

		string prev_str = "	";
		Trunk* trunk = new Trunk(prev, prev_str);

		printTree(root->left, trunk, true);

		if (!prev)
			trunk->str = "---";
		else if (isLeft)
		{
			trunk->str = ".---";
			prev_str = "	|";
		}
		else
		{
			trunk->str = "`---";
			prev->str = prev_str;
		}

		showTrunks(trunk);
		cout << root->key << endl;

		if (prev)
			prev->str = prev_str;
		trunk->str = "	|";

		printTree(root->right, trunk, false);
	}
};





int main(void) {


	Node* root = new Node(7);
	
	BST tree(root);

	tree.Insert(6);
	tree.Insert(3);
	tree.Insert(4);
	tree.Insert(9);
	tree.Insert(8);
	tree.Insert(11);
	

	tree.printTree(root, nullptr, false);
	
	
	return 0;
}
