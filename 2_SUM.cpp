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

bool reverse = true;

public:

	Constructor(Node * root , bool isReverse){
		reverse = isReverse;
		PushAll(root);
	}


	hasNext(){
		return !st.empty();
	}


	int next(){
		Node * a = st.top();
		st.pop();

		if(!reverse) PushAll(a->right);
		else PushAll(a->left);
		return a->data;
	}

	void PushAll(Node * root){
		while(root != NULL) {
			st.push(root);
			if(reverse == true){

               root = root->right;			
			}

			else{

				root = root->left;
			}
		}

	}

};

bool solve(Node * root , int target){

  if(root == NULL) return false;

// Implemantation of Binary Tree
   Constructor left(root , false);
   Constructor right(root , true);

   int i = left.next();
   int j = right.next();

 while(i < j){

		int sum = i + j;

		if(sum == target){

			return true;

		}
		else if(sum < target){

			i = left.next();
		}

		else{

			j = right.next();
	}

}

return false;

}



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


   

   // cout << left.next() <<endl;
   // cout << right.next() <<endl;
 

   cout << solve(root , 44);



}