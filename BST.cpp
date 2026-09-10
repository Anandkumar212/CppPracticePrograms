#include <iostream>

using namespace std;


struct Node {

	int data;
	Node* left;
	Node* right;

	Node(int value) {
		data=value;
		left = nullptr;
		right = nullptr;

	}

};

class bfs {

	Node* root;


	Node* insert(Node* root, int value ) {

		if(root == nullptr) {
			return new Node(value);
		}
		if(value < root->data) {
			root->left= insert(root->left,value);
		}
		else if(value > root->data) {
			root->right= insert(root->right, value);
		}
		return root;
	}

	void inorder(Node* root) {
		if(root == nullptr) {
			return;
		}
		inorder(root->left);
		cout << root->data <<" ";
		inorder(root->right);
	}
	Node* search(Node*root, int value){
	    if(root == nullptr){
	        return nullptr;
	    }
	    if(value < root->data){
	        return search(root->left, value);
	    }
	    else if ( value > root->data){
	        return search (root->right, value);
	    }
	    
	    return root;
	    
	}
	
	Node* findMin(Node* root){
	    if(root == nullptr){
	        return root;
	    }
	    if(root->left == nullptr){
	        return root;
	    }
	    return findMin(root->left);
	    
	}
	
		Node* findMax(Node* root){
	    if(root == nullptr){
	        return root;
	    }
	    if(root->right == nullptr){
	        return root;
	    }
	    return findMax(root->right);
	    
	}
public:

	bfs() {
		root = nullptr;
	}

	void insert(int value) {
		root = insert(root, value);
	}
	void inorder() {
		inorder(root);
	}
    bool search(int value){
        return search(root, value) != nullptr;
        //return root;
    }
    
    int findMin() {

    Node* node = findMin(root);

    if(node == nullptr) {
        return -1;
    }

    return node->data;
    }
    
    int findMax() {

    Node* node = findMax(root);

    if(node == nullptr) {
        return -1;
    }

    return node->data;
     }

    

};
int main() {
	bfs b;
	b.insert(10);
	b.insert(20);
	b.insert(30);
b.insert(40);
b.insert(50);
	b.inorder();
	
	if(b.search(100)){
	    cout << "found";
	}
	else
	cout <<" not found";
	
	cout<<"\n" <<b.findMin() ;
	cout<<"\n" <<b.findMax() ;
	
}