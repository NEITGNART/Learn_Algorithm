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
					cout << "Insert " << key << " successfully!\n";
					return;
				}
				q = q->left;
				continue;
			}
			if (key > q->key) {
				if (q->right == nullptr) {
					q->right = new Node(key);
					cout << "Insert " << key << " successfully!\n";
					return;
				}
				q = q->right;
				continue;
			}
		}
	}
	void Traversal(Node *root) {
		if (root != nullptr) {
			Traversal(root->left);
			cout << root->key << " ";
			Traversal(root->right);
		}
	}
};

int main(void) {


	Node* root = new Node(7);
	
	BST tree(root);

	tree.Insert(10);
	
	tree.Insert(20);

	tree.Insert(4);
	tree.Insert(2);
	tree.Insert(3);
	tree.Insert(1);
	tree.Insert(5);
	
	tree.Insert(6);
	tree.Insert(22);
	tree.Insert(10);

	
	

	tree.Traversal(root);
	
	return 0;
}
