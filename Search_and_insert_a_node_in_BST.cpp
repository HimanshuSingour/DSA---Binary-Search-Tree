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

// Insert
Node * Insert(Node * root , int val){

	if(root == NULL) return newNode(val);

	if(root->data == val) return root;

	if(val >= root->data){
		root->right = Insert(root->right , val); 
	}
	if(val <= root->data){
		root->left = Insert(root->left , val);
	}

	return root;
}

//Searching
Node * SearchIng(Node * root , int key){

	while(root != NULL && root->data != key){

		if(root->data > key){
			root = root->left;
		} 
		else{
			root = root->right;
		}
	}

	return root;
} 




int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif
// taking input

    Node* root = newNode(2); 
	root->left = newNode(1); 
	root->right = newNode(3); 


	if(SearchIng(root , 1)){
		cout << "Present";
	}
	else{
		cout << "Not Present";
	}


    


 }




