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


bool bstornot(Node * root , int mini , int maxi){

	if(root == NULL){
		return true;
	}

	if(root->data >	mini || root->data < maxi){
		return true;
	}

	return bstornot(root->left , mini , root->data) && bstornot(root->right , root->data , maxi);

}

	


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif
// taking input

    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    
  


  if(bstornot(root , INT_MIN , INT_MAX)){
  	cout << "Yes BST";
  }
  else{
  	cout << "No BST";
  }
    

 }




