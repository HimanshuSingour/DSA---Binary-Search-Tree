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

class Constructor{

stack<Node *> st;


public:

	Constructor(Node * root){
		PushAll(root);
	}


	hasNext(){
		return !st.empty();
	}


	int next(){
		Node * a = st.top();
		st.pop();
        PushAll(root->right);
		return a->data;
	}

	void PushAll(Node * root){
		while(root != NULL) {
			st.push(root);
			root = root->left;
		}

	}

};

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif
// taking input

    Node * root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(8);


   Constructor sts(root);

   cout << st.next() <<endl;





}