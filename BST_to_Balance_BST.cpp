#include<bits/stdc++.h>
using namespace std;

struct Node{
 
 public:
	int data;
	struct Node* left;
	struct Node* right;};

struct Node* newNode(int data){

	struct Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;}

// Inorder to BST or
// Normal to Balance BST

void PrintPreOrder(Node * root){

	if(root == NULL) return ;

    cout << root->data << " " ;
	PrintPreOrder(root->left);
	PrintPreOrder(root->right);

}


void storeBstToAns(Node * root , vector<Node * > & ans){

if(root == NULL) return ;
	
	PrintPreOrder(root->left);
	ans.push_back(root);
	PrintPreOrder(root->right);
}


Node * helper(vector<Node * > & ans , int s , int e){

  if(s > e) return NULL;

  int mid = (s + e) / 2;
  Node * root = ans[mid];

  root->left = helper(ans, s , mid - 1);
  root->right = helper(ans , mid + 1 , e);
  return root;
 

}

Node * solve(Node * root){
 
    vector<Node * > ans;
 	storeBstToAns(root , ans);


 	return helper(ans , 0 , ans.size() - 1);
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
    Node* root = newNode(4);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->left->left = newNode(1);

    
   


   PrintPreOrder(root);

   cout << endl;

   solve(root);

   PrintPreOrder(root);




 

}