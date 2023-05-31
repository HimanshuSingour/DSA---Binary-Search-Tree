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

/* logic :: 


if(root == NULL) return NULL;

    Checking for Out of range Conditions


if(preOrder[index] >= INT_MAX  || preOrder[index] <= INT_MIN)
    return NULL;


    //Create a Node

   Node * newnode = newNode(i);
   i++;


    // Now we Going To left and Right

root->left = function(root->left , min , root->data);
root->right = function(root->right , root->data , max);
return root;



*/

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

    cout << PreToBST(root , 1 , 5)->data;


}

    




