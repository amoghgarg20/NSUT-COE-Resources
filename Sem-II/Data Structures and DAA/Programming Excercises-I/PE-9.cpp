#include<iostream>
using namespace std;
 class node{
 public:
 	int data;
 	node* next;
 	node* prev;

 	node(int d){
 		data=d;
 		next=NULL;
 		prev=NULL;
 	}
};
void insert(node* &head,node* &tail,int d){
	node* n=new node(d);
	if(head==NULL){
		head=n;
		tail=n;
	}
	else{
		tail->next=n;
		n->prev=tail;
		tail=n;
	}
}
void del(node* &head,node* &tail,int val){
	if(head==NULL){
		cout<<"Empty List!"<<endl;
		exit(1);
	}
	node* temp=head;
	while(temp->data != val){
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	delete temp;
}
void display(node* head,node* tail){
	if(head==NULL){
		cout<<"Empty List!"<<endl;
	}
	else if(head==tail){
		cout<<head->data<<endl;
	}
	else if(head->next==tail){
		cout<<"NULL->"<<head->data<<"->"<<tail->data<<endl;

	}
	else{
		cout<<"NULL->"<<head->data<<"->"<<head->next->data<<endl;
		while(head->next != tail->prev){
			head=head->next;
			cout<<head->prev->data<<"->"<<head->data<<"->"<<head->next->data<<endl;
		}
		cout<<tail->prev->data<<"->"<<tail->data<<"->"<<"NULL"<<endl;
	}
}
int main(){
	node* head=NULL,*tail=NULL;
	cout<<"1.Insert at end"<<endl;
	cout<<"2.Delete particular element"<<endl;
	cout<<"3.Display List"<<endl;
	cout<<"4.Exit"<<endl;
	while(1){
		int c;
		cout<<"Enter choice:";
		cin>>c;
		if(c==1){
			int d;
			cout<<"Enter the value:";
			cin>>d;
			insert(head,tail,d);
		}
		else if(c==2){
			int d;
			cout<<"Enter the value:";
			cin>>d;
			del(head,tail,d);
			cout<<"Element deleted"<<endl;
		}
		else if(c==3){
			display(head,tail);
		}
		else if(c==4){
			return 0;
		}
		else{
			cout<<"Wrong choice!"<<endl;
		}
	}
}