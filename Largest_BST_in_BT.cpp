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


vector<int> solveLargestrBStsize(Node * root){

// if not left or not right
 if(!root) return {1 , 0 , INT_MAX , INT_MIN};  //(Bst or Not , size , data , data)

 // left and right both not exist
 if(root->left == NULL && root->right == NULL) return {1 , 1 , root->data , root->data}; 


    vector<int> l = solveLargestrBStsize(root->left);
    vector<int> r = solveLargestrBStsize(root->right);

 // if both having BST 
   if(l[0] && r[0] == 1){

   	// take -> left larger element 
   	// take -> right smaller element
   	 if(root->data > l[3] && root->data < r[2]){
        
       int x = l[2];
       int y = r[3];
       

       if(x == INT_MAX) x = root->data;
       if(y == INT_MIN) y = root->data;

   	 	return {1 , l[1] + r[1] + 1 , x , y};
   	 }
   }

   return {0 , max(l[1] , r[1]) , 0 , 0};

}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
    Node* root = newNode(60);
    root->left = newNode(65);
    root->right = newNode(70);
    root->left->left = newNode(50);


   vector<int> a = solveLargestrBStsize(root);

   for(auto i : a){
   	cout << i << endl;
   }
 

}