#include <bits/stdc++.h>
using namespace std;

class node{
public:
	char data;
	unsigned freq;
	node * left; 
	node * right;

	node(char d, unsigned f){
		data=d;
		freq=f;
		right=NULL;
		left=NULL;
	}
};
// For Min Heap
class myComparator{
public:
    int operator()(node* p1,node* p2){
        return p1->freq>p2->freq;
    }
};
void printc(node* root,string str){
	if (root==NULL)
		return;
	if (root->data != '$')
		cout<<root->data<<": "<<str<<endl;
	printc(root->left,str + "0");
	printc(root->right,str + "1");
}
void Encoding(char data[],int freq[],int size){
	node *left, *right, *top;
	// Built in Min Heap
	priority_queue<node*, vector<node*>,myComparator> minHeap;
	for (int i=0;i<size;++i){
		minHeap.push(new node(data[i], freq[i]));
	}
	while (minHeap.size() != 1) {
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new node('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	printc(minHeap.top(),"");
}
int main(){
	char a[] = {'a','b','c','d','e','f'};
	int freq[] = {5,9,12,13,16,45};
	int n= sizeof(a)/sizeof(a[0]);
	Encoding(a,freq,n);
	return 0;
}
