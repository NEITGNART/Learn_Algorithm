#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
 
using namespace std;
 
#define Vi vector<vector<int> >
#define FOR(i, n) for (int i = 0; i < n; ++i)
 
struct Node {
    int key;
    Node *left = 0;
    Node *right = 0;
    Node(int key) : key(key), left(0), right(0) {}
    Node () = default;
};
 
void Insert(Node *&root, int x) {
    if (root == nullptr) {
        root = new Node(x);
        return;
    }
    else if (root->key == x) return;
    else if (root->key > x) Insert(root->left, x);
    else if (root->key < x) Insert(root->right, x);
}
 
void Postorder(Node *root) {
    if (root) {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->key << " ";
    }
}
 
void ReadFile(ifstream &fin, Node *&root, int &G) {
    fin.open("/Users/macbookpro/Downloads/Practice/Practice/inputTree.txt");
    string temp;
    getline(fin, temp);
    int n;
    istringstream is(temp);
    while (is >> n) {
 
        Insert(root, n);
    }
    fin >> G;
}
 
int Height(Node *root) {
    if (root == nullptr) return 0;
    return max(Height(root->left), Height(root->right)) + 1;
}
 
bool isAVL(Node *root) {
    if (root == nullptr) return true;
    int x = abs(Height(root->left) - Height(root->right));
    if (x >= 2) return false;
    return isAVL(root->left) && isAVL(root->right);
}
 
void Delete(Node *&root, int x) {
    if (root == nullptr) {
        return;
    } else if (root->key > x) {
        Delete(root->left, x);
    }else if (root->key < x) {
        Delete(root->right, x);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            Node *p = root;
            root = root->right;
            delete p;
        }
        else if (root->right == nullptr) {
            Node *p = root;
            root = root->right;
            delete p;
        }
        else if (root->right && root->left) {
            Node *successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            root->key = successor->key;
            Delete(root->right, successor->key);
        }
    }
}
 
int _max = INT_MIN;
 
void Inorder(Node *&root) {
    if (root) {
        Inorder(root->right);
        if (root->left && root->right && isAVL(root)) {
            _max = max(_max, root->key);
        }
        Inorder(root->left);
    }
}
 
int Sum(Node *root) {
    if (root == nullptr) return 0;
    return root->key + Sum(root->left) + Sum(root->right);
}
 
void gogo2(Node *root, int G) {
    if(root) {
        gogo2(root->left, G);
        if (Sum(root->left) - Sum(root->right) <= G){
            cout << root->key << " ";
        }
        gogo2(root->right, G);
    }
}
 
int main(void) {
 
    Node *root = nullptr;
    ifstream fin;
    int G;
    ReadFile(fin, root, G);
    cout << "Tree: ";
    Postorder(root);
    cout << endl << endl;
 
    gogo2(root, G);
    cout << endl << endl;
    Inorder(root);
    Delete(root, _max);
    cout << "After delete: ";
 
    Postorder(root);
 
    return 0;
}
