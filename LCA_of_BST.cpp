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

Node * LCSBST(Node * root , int a , int b){

	if(root == NULL) return root;


	if(a < root->data && b < root->data){
		return LCSBST(root->left , a , b);

	}

	if(a > root->data && b > root->data){
		return LCSBST(root->right , a , b);
	}

	return root;


	while(root != NULL){

		if(a < root->data && b < root->data){
			root = root->left;
		}

		if(a > root->data && b > root->data){
			root = root->right;
		}
		else{
			break;
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

    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    cout << LCSBST(root , 1 , 5)->data;


}

    




