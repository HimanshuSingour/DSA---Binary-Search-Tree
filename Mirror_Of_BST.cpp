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


void swap(int *a , int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void mirrotTree(Node * root){

	if(root == NULL) return;

	 queue<Node *> q;
	 q.push(root);

	 while(!q.empty()){
	 	Node * a = q.front();
	 	q.pop();

	 	swap(a->left , a->right);

	 	if(a->left){
	 		q.push(a->left);
	 	}

	 	if(a->right){
	 		q.push(a->right);
	 	}
	 }
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
   struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
   


print(root);

cout << endl;
mirrotTree(root);    
print(root);





 

}