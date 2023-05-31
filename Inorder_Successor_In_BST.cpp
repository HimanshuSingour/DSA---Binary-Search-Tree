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

Node * Successor(Node * root , int k){

	Node * Successora = NULL;

	while(root != NULL){

		if(k >= root->data){
			root = root->right;
		}
		else{

            Successora = root;
            cout << "Sequence :" << Successora->data << endl;
			root = root->left;
		}
	}

	return Successora;

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

    cout << Successor(root , 2)->data;


}

    




