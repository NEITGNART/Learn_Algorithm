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
	void Traversal(Node *root, int depth) {
		if (root != nullptr) {
			for (int i = 0; i < depth; ++i) cout << "  ";
			cout << root->key << " " << endl;
			Traversal(root->left, depth+1);
			Traversal(root->right, depth+1);
		}
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
	

	tree.Traversal(root, 1);
	
	
	return 0;
}
