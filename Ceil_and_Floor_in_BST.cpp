#include<bits/stdc++.h>
using namespace std;

struct Node{
 
 public:
	int data;
	struct Node* left;
	struct Node* right;};

void Inorder(Node * root){
	if(root == NULL) return;

	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);}

struct Node* newNode(int data){
	
	struct Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;}


// Ceil -> Find smalles Number which is greates than Given Number Key

int CeilOfBST(Node * root , int k){


  int ans = -1;

  while(root){

  	  if(root->data == k){
  	  	ans = root->data;
  	  	return ans;
  	  }
  	  if(k > root->data){
  	  	// ans = root->data; // for flore
  	  	root = root->right;
  	  }
  	  else{
  	  	ans = root->data; // for ceil
  	  	root = root->left;
  	  }
  }

  return ans;
}



int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif
// taking input

    Node* root = newNode(8); 
	root->left = newNode(4); 
	root->right = newNode(12);
	root->left->left = newNode(2);
	root->left->right = newNode(6);
	root->right->left = newNode(10);
	root->right->right = newNode(14); 
   

   cout << CeilOfBST(root , 11);

    


 }




