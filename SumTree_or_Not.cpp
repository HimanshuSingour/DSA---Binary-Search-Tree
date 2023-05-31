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

int solbve(Node * root , int & f){

	if(!root) return 0;

	if(!root->left && !root->right) return root->data;

	if(f == 0) return 0;
   
	int a = solbve(root->left , f);
	int b = solbve(root->right , f);
    
    if(a + b != root->data) return f = 0;
    else return a + b + root->data;
}
bool SumTree(Node * root){


	int f = 1;
	solbve(root , f);
	return f;
    

	

}




int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
    Node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);


if(SumTree(root)){

	cout << "yes";
}
else{

	cout << "No";

}
 

}