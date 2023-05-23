//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
// } Driver Code Ends

#include<bits/stdc++.h>
/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively

void inOrder(Node* root , vector<Node*> &temp){
    if(root == NULL) return;
    
    inOrder(root->left ,temp);
    temp.push_back(root);
    inOrder(root->right , temp);
}

void successor(Node* root , int key, Node*& suc){
    if(root == NULL) return;
    if(key >= root->key){
        successor(root->right , key , suc);
    }else{
        suc = root;
        successor(root->left , key , suc);
    }
    
}

void predecessor(Node* root , int key, Node*& pre){
    if(root == NULL) return;
    if(key <= root->key){
        
        predecessor(root->left , key , pre);
    }else{
       pre = root;
        predecessor(root->right , key , pre);
    }
    
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// pre = NULL;
// suc = NULL;

// Your code goes here
// vector<Node*> temp;
// inOrder(root , temp);

// for(int i = 0 ; i < temp.size(); i++){
//     if(temp[i]->key < key) pre = temp[i];
// }

// for(int i = temp.size() - 1; i >= 0; i--){
//     if(temp[i]->key > key) suc = temp[i];
// }

successor(root , key  , suc);
predecessor(root , key , pre);


}
