A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than or equal to the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.
Insert a sequence of numbers into an initially empty binary search tree. Then you are supposed to count the total number of nodes in the lowest 2 levels of the resulting tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤1000) which is the size of the input sequence. Then given in the next line are the N integers in [−10001000] which are supposed to be inserted into an initially empty binary search tree.

Output Specification:
For each case, print in one line the numbers of nodes in the lowest 2 levels of the resulting tree in the format:

n1 + n2 = n
where n1 is the number of nodes in the lowest level, n2 is that of the level above, and n is the sum.

Sample Input:
9
25 30 42 16 20 20 35 -5 28
Sample Output:
2 + 4 = 6
#include<cstdio>

int n,n1=0,n2=0,maxh=0;
struct node{
    int data,height;
    node *lc,*rc;
    node(int _data,int _height){
        data=_data;
        height=_height;
        lc=rc=NULL;
    }
};

void insert(node* &root,int data,int height){
    if(root==NULL){
        root=new node(data,height);
        if(height>maxh){
            maxh=height;
        }
        return;
    }
    if(data>root->data){
        insert(root->rc,data,root->height+1);
    }else{
        insert(root->lc,data,root->height+1);
    }
}

void in(node *root){
    if(root==NULL)return;
    in(root->lc);
    if(root->height==maxh){
        n1++;
    }else if(root->height==maxh-1){
        n2++;
    }
    in(root->rc);
}

int main(){
    node *root=NULL;
    scanf("%d",&n);
    int temp;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        insert(root,temp,1);
    }
    in(root);
    printf("%d + %d = %d",n1,n2,n1+n2);
    return 0;
}
