#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* next;
	node(int d){
		data=d;
		next=NULL;
	}
};
class Queue{
	node* head;
	node* tail;
	int len;
public:
	Queue(){
		head=NULL;
		tail=NULL;
		len=0;
	}
	void enqueue(int d){
		node* n=new node(d);
		if(head==NULL){
			head=n;
			tail=n;
			len++;
		}
		else{
			tail->next=n;
			tail=n;
			len++;
		}
	}
	void dequeue(){
		if(head==NULL){
			cout<<"Queue Underflow!"<<endl;
		}
		else if(head->next==NULL){
			delete head;
			head=NULL;
			tail=NULL;
			len--;
		}
		else{
			node* n=head;
			head=n->next;
			delete n;
			len--;
		}
	}	
	int front(){
		return head->data;
	}
	bool empty(){
		return head==NULL;
	}
	int size(){
		return len;
	}
	void display(){
		node* temp=head;
		cout<<"The queue is:";
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};
class Stack{
	node* head;
	int len;
public:
	Stack(){
		head=NULL;
		len=0;
	}
	void push(int d){
		node* n=new node(d);
		n->next=head;
		head=n;
		len++;
	}
	void pop(){
		if(head==NULL){
			cout<<"Stack Underflow!"<<endl;
		}
		else if(head->next==NULL){
			delete head;
			head=NULL;
			len--;
		}
		else{
			node* temp=head;
			head=head->next;
			delete temp;
			len--;
		}
	}
	bool empty(){
		return head==NULL;
	}
	int size(){
		return len;
	}
	int top(){
		return head->data;
	}
	void display(){
		node* temp=head;
		cout<<"The stack is:";
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}

};
int main(){
	int c;
	cout<<"Enter '1' for Queue and '2' for Stack:";
	cin>>c;
	if(c==1){
		Queue q;
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Check size"<<endl;
		cout<<"4.Check whether empty or not"<<endl;
		cout<<"5.Display 1st element"<<endl;
		cout<<"6.Display entire queue"<<endl;
		cout<<"7.Exit"<<endl;
		while(1){
			int x;
			cout<<"Enter choice:";
			cin>>x;
			if(x==1){
				int d;
				cout<<"Enter the value:";
				cin>>d;
				q.enqueue(d);
				cout<<"Value Added"<<endl;
			}
			else if(x==2){
				q.dequeue();
				cout<<"Element Removed"<<endl;
			}
			else if(x==3){
				cout<<"Size of array is:"<<q.size()<<endl;
			}
			else if(x==4){
				if(q.empty()){
					cout<<"Queue is empty"<<endl;
				}
				else{
					cout<<"Queue is not empty"<<endl;
				}
			}
			else if(x==5){
				cout<<"The first element is:"<<q.front()<<endl;
			}
			else if(x==6){
				q.display();
			}
			else if(x==7){
				cout<<"Exiting..."<<endl;
				return 0;
			}
			else{
				cout<<"Wrong Input"<<endl;
			}

		}
	}
	else if(c==2){
		Stack s;
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Check size"<<endl;
		cout<<"4.Check whether empty or not"<<endl;
		cout<<"5.Display top element"<<endl;
		cout<<"6.Display entire stack"<<endl;
		cout<<"7.Exit"<<endl;
		while(1){
			int x;
			cout<<"Enter choice:";
			cin>>x;
			if(x==1){
				int d;
				cout<<"Enter the value:";
				cin>>d;
				s.push(d);
				cout<<"Value Added"<<endl;
			}
			else if(x==2){
				s.pop();
				cout<<"Element Removed"<<endl;
			}
			else if(x==3){
				cout<<"Size of array is:"<<s.size()<<endl;
			}
			else if(x==4){
				if(s.empty()){
					cout<<"Stack is empty"<<endl;
				}
				else{
					cout<<"Stack is not empty"<<endl;
				}
			}
			else if(x==5){
				cout<<"The first element is:"<<s.top()<<endl;
			}
			else if(x==6){
				s.display();
			}
			else if(c==7){
				cout<<"Exiting..."<<endl;
				return 0;
			}
			else{
				cout<<"Wrong Input"<<endl;
			}
		}
	}
	else{
		cout<<"Wrong Input...Exiting..."<<endl;
		return 0;
	}
}