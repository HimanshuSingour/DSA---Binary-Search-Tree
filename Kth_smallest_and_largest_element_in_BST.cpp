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

// MOrris Algorithum
Node * KthLargestNumber(Node * root , int k){

	Node * curr = root;
	Node * ans = NULL;
	int count = 0;

	while(curr != NULL){
		if(curr->left == NULL){
			if(count == k){
				ans = curr;
			}

            curr = curr->right;
		}
		else{

			Node * prev = curr->left;

			while(prev->right && prev->right != curr){
				prev = prev->right;
			}

			if(prev->right == NULL){
				prev->right = curr;
				curr = curr->left;
			}
			else{

				prev->right = NULL;
				if(k == count){
					ans = curr;
				}

	         	curr = curr->right;
			}
		}
	}

	return ans;
}


// Node * KthLargestNormal(Node * root , int k , int & count){
    

// 	if(root == NULL) return NULL;

// 	Node * left = KthLargestNormal(root->left , k , count);

// 	if(left != NULL){
// 		return left;

// 	}

// 	count++;

// 	if(count == k){
// 		return root;
// 	}


//    return KthLargestNormal(root->right , k , count);
  
   
// }




int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif
// taking input

    Node* root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(4);
    root->left->right = newNode(2);
  


    Node * ans = KthLargestNumber(root , 4);
    cout << ans->data;
    

 }




