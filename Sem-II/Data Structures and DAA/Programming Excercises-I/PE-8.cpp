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
void enqueue(node* &head,node* &tail,int d){
	node* n=new node(d);
	if(head==NULL){
		head=n;
		tail=n;
		tail->next=n;
	}
	tail->next=n;
	n->next=head;
	tail=n;
}
void dequeue(node* &head,node* &tail){
	if(head==NULL){
		cout<<"Queue Underflow!"<<endl;
		exit(1);
	}
	node* temp=head;
	int val=temp->data;
	head=temp->next;
	tail->next=head;
	delete temp;
	cout<<val<<"->Deleted"<<endl;
}
void push(node* &head,node* &tail,int d){
	node *n=new node(d);
	if(head==NULL){
		head=n;
		tail=n;
		tail->next=n;
	}
	tail->next=n;
	n->next=head;
	head=n;
}
bool empty(node* &head){
	return head==NULL;
}
void pop(node* &head,node* &tail){
	if(head==NULL){
		cout<<"Stack Underflow!"<<endl;
		exit(1);
	}
	else if(head==tail){
		cout<<head->data<<"->Deleted"<<endl;
		delete head;
		delete tail;
		head=NULL;
		tail=NULL;
	}
	node *temp=head;
	int val=temp->data;
	head=temp->next;
	tail->next=head;
	delete temp;
	cout<<val<<"->Deleted"<<endl;
}
void display(node* head,node* tail){
	if(head==NULL){
		cout<<"Empty"<<endl;
	}
	else{
		while(!empty(head) && head != tail){
			cout<<head->data<<"->";
			head=head->next;
		}
		cout<<head->data<<"->";
		cout<<endl;
	}
}
void joincircularlist(node* &head1,node* &tail1,node* &head2,node* &tail2){
	tail1->next=head2;
	tail2->next=head1;	
}
int main(){
	cout<<"1.Create Circular Queue"<<endl;
	cout<<"2.Create Circular Stack"<<endl;
	cout<<"3.Join two circular linked list"<<endl;
	int c;
	cout<<"Enter choice:";
	cin>>c;
	if(c==1){
		node *head=NULL,*tail=NULL;
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Check Empty"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"5.Exit"<<endl;
		while(1){
		cout<<"Enter choice:";
		int x;
		cin>>x;
		if(x==1){
			int d;
			cout<<"Enter data:";
			cin>>d;
			enqueue(head,tail,d);
		}
		else if(x==2){
			dequeue(head,tail);
		}
		else if(x==3){
			if(empty(head)){
				cout<<"Queue Empty!"<<endl;
			}
			else{
				cout<<"Queue not empty!"<<endl;
			}
		}
		else if(x==4){
			display(head,tail);
		}
		else if(x==5){
			return 0;
		}
		else{
			cout<<"Wrong Input"<<endl;
		}
	}
    }
	else if(c==2){
		node* head=NULL,*tail=NULL;
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Check Empty"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"5.Exit"<<endl;
		while(1){
		cout<<"Enter choice:";
		int x;
		cin>>x;
		if(x==1){
			int d;
			cout<<"Enter data:";
			cin>>d;
			push(head,tail,d);
		}
		else if(x==2){
			pop(head,tail);
		}
		else if(x==3){
			if(empty(head)){
				cout<<"Stack Empty!"<<endl;
			}
			else{
				cout<<"Stack not empty!"<<endl;
			}
		}
		else if(x==4){
			display(head,tail);
		}
		else if(x==5){
			return 0;
		}
		else{
			cout<<"Wrong Input"<<endl;
		}
	}
    }
	else if(c==3){
		node* head1=NULL,*tail1=NULL;
		node* head2=NULL,*tail2=NULL;
		int n1,n2;
		cout<<"Enter length of list-1:";
		cin>>n1;
		cout<<"Enter length of list-2:";
		cin>>n2;
		cout<<"Enter elements of list-1:";
		for(int i=0;i<n1;i++){
			int d;
			cin>>d;
			enqueue(head1,tail1,d);
		}
		cout<<"Enter elements of list-2:";
		for(int i=0;i<n2;i++){
			int d;
			cin>>d;
			enqueue(head2,tail2,d);
		}
		joincircularlist(head1,tail1,head2,tail2);
		cout<<"Joint List is:";
		display(head1,tail2);
		return 0;
	}
}