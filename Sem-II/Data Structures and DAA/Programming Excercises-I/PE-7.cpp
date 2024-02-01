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
void insertatfront(node* &head,node* &tail,int d){
	node* n=new node(d);
	if(head==NULL){
		head=n;
		tail=n;
	}
	else{
		n->next=head;
		head=n;
	}
}
void insertatend(node* &head,node* &tail,int d){
	node* n=new node(d);
	if(head==NULL){
		head=n;
		tail=n;
	} 
	else{
		tail->next=n;
		tail=n;
	}
}
int length(node* head){
	int cnt=0;
	while(head != NULL){
		cnt++;
		head=head->next;
	}
	return cnt;


}
void insertatpos(node* &head,node* &tail,int d,int pos){
	node* n=new node(d);
	pos=pos-1; //Here position starts from 1
	if(pos==0){
		insertatfront(head,tail,d);
	}
	else if(pos==length(head)-1){
		insertatend(head,tail,d);
	}
	else{
		node* temp=head;
		node* n=new node(d);
		for(int i=1;i<pos;i++){
			temp=temp->next;
		}
		n->next=temp->next;
		temp->next=n;
	}
}
void insertafterval(node* &head,node* &tail,int val,int d){
	node* temp=head;
	node* n=new node(d);
	while(temp->data != val){
		temp=temp->next;
	}
	node* x=temp->next;
	temp->next=n;
	n->next=x;
}
void display(node* head){
	while(head != NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}
void deletefromfront(node* &head,node* &tail){
	if(head==NULL){
		cout<<"Empty List!"<<endl;
	}
	else if(head->next==NULL){
		delete head;
		head=NULL;
		tail=NULL;
	}
	else{
		node* n=head;
		head=head->next;
		delete n;
	}
}
void deletefromend(node* &head,node* &tail){
	if(head==NULL){
		cout<<"Empty List!"<<endl;
	}
	else if(head->next==NULL){
		delete head;
		head=NULL;
		tail=NULL;
	}
	else{
		node* temp=head;
		while(temp->next != tail){
			temp=temp->next;
		}
		temp->next=NULL;
		delete tail;
		tail=temp;
	}
}
void deletefrompos(node* &head,node* &tail,int pos){
	pos=pos-1;  //Here position starts from 1
	if(pos==0){
		deletefromfront(head,tail);
	}
	else if(pos==length(head)-1){
		deletefromend(head,tail);
	}
	else{
		node* temp=head;
		for(int i=1;i<pos;i++){
			temp=temp->next;
		}
		node* n=temp->next;
		temp->next=n->next;
		delete n;
	}
}
void deleteval(node* &head,node* &tail,int val){
	node* temp=head;
	while((temp->next)->data != val){
		temp=temp->next;
	}
	node* n=temp->next;
	temp->next=temp->next->next;
	delete n;
}
void reversell(node*&head){
	node*c=head;
	node *prev=NULL;
	node*n=NULL;
	while(c){
		n=c->next;
		c->next=prev;
		prev=c;
		c=n;
	}
	head=prev;
}
void bubblesort(node* &head,int l){
	for(int i=0;i<l-1;i++){
		int count=0;
		node* temp=head;
		node* temp2=head->next;
		for(int j=0;j<l-i-1;j++){
			if(temp->data>temp2->data){
				int x=temp->data;
				temp->data=temp2->data;
				temp2->data=x;
				count++;
			}
			temp=temp2;
			temp2=temp2->next;			
		}
		if(count==0){
			break;
		}
	}
}
int main(){
	cout<<"1.Insert element at position"<<endl;
	cout<<"2.Insert element after particular element"<<endl;
	cout<<"3.Delete element at position"<<endl;
	cout<<"4.Delete element by value"<<endl;
	cout<<"5.Reverse Linked List"<<endl;
	cout<<"6.Display the list"<<endl;
	cout<<"7.Length of List"<<endl;
	cout<<"8.Bubble Sort"<<endl;
	cout<<"9.Exit"<<endl;
	node *head=NULL,*tail=NULL;
	while(1){
		int c;
		cout<<"Enter Choice:";
		cin>>c;
		if(c==1){
			int d,p;
			cout<<"Enter the value:";
			cin>>d;
			cout<<"Enter the position:";
			cin>>p;
			insertatpos(head,tail,d,p);
		}
		else if(c==2){
			int d,p;
			cout<<"Enter the value:";
			cin>>d;
			cout<<"Enter the element after which it has to be added:";
			cin>>p;
			insertafterval(head,tail,p,d);
		}
		else if(c==3){
			int p;
			cout<<"Enter the position:";
			cin>>p;
			deletefrompos(head,tail,p);
		}
		else if(c==4){
			int p;
			cout<<"Enter the value:";
			cin>>p;
			deleteval(head,tail,p);
		}
		else if(c==5){
			reversell(head);
		}
		else if(c==6){
			display(head);
		}
		else if(c==7){
			cout<<"Length of list:"<<length(head)<<endl;
		}
		else if(c==8){
			bubblesort(head,length(head));
		}
		else if(c==9){
			cout<<"Exiting..."<<endl;
			return 0;
		}
		else{
			cout<<"Wrong Input"<<endl;
		}

	}
}