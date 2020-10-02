// { Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}

Node* insertToAVL( Node* node, int data);

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        
        for(int i=0; i<n; i++)
        {
            root = insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}// } Driver Code Ends


/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

int height(Node *N)  
{  
	
    if (N == NULL)  
        return 0;  
    int l = height(N->left);
    int r = height(N->right);
	return max(l, r) + 1;
} 


Node* rightRotation(Node* node) {
    Node *x = node->left;
    Node *T2 = x->right;
    
    x->right = node;
    node->left = T2;
    
    x->height =  max(height(x->left), height(x->right)) +1;
    node->height =  max(height(node->left), height(node->right)) +1;
    
    return x;
    
}

Node *leftRotation(Node *node) {
    Node *x = node->right;
    Node *T2 = x->left;
    x->left = node;
    node->right = T2;
    x->height =  max(height(x->left), height(x->right)) +1;
    node->height =  max(height(node->left), height(node->right)) +1;
    
    return x;
    
}


// Node *rightRotation(Node *y)  
// {  
//     Node *x = y->left;  
//     Node *T2 = x->right;  
  
//     // Perform rotation  
//     x->right = y;  
//     y->left = T2;  
  
//     // Update heights  
//     y->height = max(height(y->left), 
//                     height(y->right)) + 1;  
//     x->height = max(height(x->left), 
//                     height(x->right)) + 1;  
  
//     // Return new root  
//     return x;  
// }  
  
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
// Node *leftRotation(Node *x)  
// {  
//     Node *y = x->right;  
//     Node *T2 = y->left;  
  
//     // Perform rotation  
//     y->left = x;  
//     x->right = T2;  
  
//     // Update heights  
//     x->height = max(height(x->left),     
//                     height(x->right)) + 1;  
//     y->height = max(height(y->left),  
//                     height(y->right)) + 1;  
  
//     // Return new root  
//     return y;  
// }  


/*You are required to complete this method */
Node* insertToAVL(Node* node, int data)
{
    if (node == nullptr) {
        node = new Node(data);
    }
    if (data > node->data) {
        node->right = insertToAVL(node->right, data);
    }
    else if (data < node->data){
        node->left = insertToAVL(node->left, data);
    }
    else return node;
    
    node->height = max(height(node->left), height(node->right)) + 1;
    
    int balance = height(node->left) - height(node->right);
    
    if (balance > 1 && data < node->left->data) {
        return rightRotation(node);
    }
    
    if (balance < -1 && data > node->right->data) {
        return leftRotation(node);
    }
    
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    return node;
}
