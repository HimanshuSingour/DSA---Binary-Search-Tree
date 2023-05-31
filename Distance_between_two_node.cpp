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

void print(Node * root){
	if(root == NULL) return;

	print(root->left);
    cout << root->data << " ";
	print(root->right);}


int distance(Node * root , int x){

	if(root->data == x) return 0;

	if(root->data > x) return 1 + distance(root->left , x);
	else  return 1 + distance(root->right , x);
}

int LCA(Node * root , int n1 , int n2){

	if(root == NULL) return 0;

	
	if(n1 < root->data && n2 < root->data){
		return LCA(root->left , n1 , n2);
	}

	if(n1 > root->data && n2 > root->data){
		return LCA(root->right , n1 , n2);
	}

   
	
	int d1 = distance(root , n1);
	int d2 = distance(root , n2);

	return d1 + d2;

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
   


cout << LCA(root , 1 , 5);
 



 

}