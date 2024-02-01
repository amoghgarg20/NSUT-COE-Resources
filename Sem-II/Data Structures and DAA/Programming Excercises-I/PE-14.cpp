#include <iostream>
#include <string>
using namespace std;

class node{
public:
	int data;
	node * left;
	node * right;
	//Node Constructor
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};
node* insertinbst(node* root,int d){
	//Base Case
	if(root==NULL){
		root=new node(d);
		return root;
	}
	//Recursive Case
	if(d<root->data){
		root->left=insertinbst(root->left,d);
	}
	else{
		root->right=insertinbst(root->right,d);
	}
	return root;
}
void inorder(node* root){
	//Base Case
	if(root==NULL){
		return;
	}
	//Recursive Case
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
node* deleteinbst(node*root,int key){
	// Case 1 --> Key in LST
	if(root->data>key){
		root->left=deleteinbst(root->left,key);
		return root;
	}
	// Case 2 --> Key in RST
	else if(root->data<key){
		root->right=deleteinbst(root->right,key);
		return root;
	}
	else{
		// No Child
		if(root->left==NULL&&root->right==NULL){
			delete root;
			return NULL;
		}
		//One Child
		// Right Child Exists
		else if(root->right!=NULL&&root->left==NULL){
			node*temp=root->right;
			delete root;
			return temp;
		}
		// Left Child Exists
		else if(root->right==NULL&&root->left!=NULL){
			node*temp=root->left;
			delete root;
			return temp;
		}
		// Two Child;
		else{
			node*replace=root->right;
			while(replace->left != NULL){
				replace=replace->left;
			}
			swap(root->data,replace->data);
			root->right=deleteinbst(root->right,replace->data);
			return root;
		}
	}
}
int main(){
	node* root=NULL;
	string c="Y";
	cout<<"1. Insert Element"<<endl;
	cout<<"2. Delete Element"<<endl;
	while(c=="Y"){
		int o;
		cout<<"Enter choice:";
		cin>>o;
		if(o==1){
			cout<<"Enter the element to insert in BST:";
			int d;
			cin>>d;
			root=insertinbst(root,d);
		}
		else if(o==2){
			cout<<"Enter the element to delete from BST:";
			int d;
			cin>>d;
			root=deleteinbst(root,d);
		}
		else{
			cout<<"Wrong Input!"<<endl;
		}
		cout<<"Do you want to continue?(Y/N):";
		cin>>c;
	}
	cout<<"Inorder traversal of BST:";
	inorder(root);
	cout<<endl;
	return 0;
}