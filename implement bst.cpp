#include <iostream>
//constructing a node
using namespace std;
struct node_bst{
	int data;
	node_bst* left;
	node_bst* right;
};node_bst*root;
node_bst* getNewNode(int item){
	node_bst* new_node=new node_bst();
	new_node->data=item;
	new_node->left = new_node->right = NULL;
	return new_node;
}
//INORDER
void printinorder(node_bst* root)
{
    if (root == NULL)
        return;
 	    printinorder(root->left);
		cout << root->data << " ";
    	printinorder(root->right);
}
node_bst* insert(node_bst*root, int data){
	if(root == NULL){
		root=getNewNode(data);
	}
	else if(data<= root->data)
		root->left=insert(root->left, data);
		
	else
		root->right=insert(root->right, data);
		
	return root;
}
bool search(node_bst* root, int data){
	if(root==NULL) return false;
	else if(root->data==data) return true;
	else if(data<=root->data) return search(root->left, data);
	else return search(root->right, data);
}
int find_min(node_bst*root){
	if(root==NULL){
		cout<<"The tree is empty.";
		return -1;
	}
	while(root->left!=NULL){//rootun lefti 0 olana kadar ilerle
		root=root->left;
	}
	return root->data;
}
struct node_bst* Delete(struct node_bst* root, int data){
	if(root==NULL) return root;
	else if(data< root->data) root->left = Delete(root->left, data);
	else if(data> root->data) root->right = Delete(root->right, data);
	else{
		//if node has no child
		if(root->left==NULL && root->right==NULL){
			delete root;
			root=NULL;
		}
		//has one child
		else if(root->left==NULL){
			struct node_bst* temp=root;
			root=root->right;
			delete temp;
		}
		else if(root->right==NULL){
			struct node_bst* temp=root;
			root=root->left;
			delete temp;
		}
		//has 2 children
		else{
			struct node_bst *temp =find_min(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
		return root;
	}
}
int find_max(node_bst*root){
	if(root==NULL){
	cout<<"The tree is empty.";
	return -1;	
	}
	while(root->right!=NULL){
		root=root->right;
	}
	return root->data;
}
int main(){
	node_bst* root=NULL;
	root = insert(root, 35);
	root = insert(root, 27);
	root = insert(root, 54);
	root = insert(root, 25);
	root = insert(root, 37);
	root = insert(root, 44);
	cout<<"The smallest data in this tree is: \n" <<find_min(root);
	cout<<"\n";
	cout<<"The highest number in the tree is: \n" <<find_max(root);
	cout<<"\n";
	int num, number;
	cout<<"Enter the number that you want to search:\n";
	cin>>num;
	if(search(root,num)==true){
	cout<<"The number has found\n";
	}
	else{
	cout<<"Not found.\n";
	}
	int a;
	cout<< "1 for print in order\n2 for delete a number that you want to delete";
	cout<< "Enter your choice: \n";
	cin>> a;
	while(1){
	switch(a)
	{
		case 1: printinorder(root); break;
		case 2: cin>>number; Delete(root, number); break;
		return 1;
	}
	}
}
	
	
	

