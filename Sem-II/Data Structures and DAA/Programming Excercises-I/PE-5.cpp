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
int main(){
	node* head=NULL,*tail=NULL;
	cout<<"1.Insert at front"<<endl;
	cout<<"2.Insert at end"<<endl;
	cout<<"3.Insert at given index"<<endl;
	cout<<"4.Delete from front"<<endl;
	cout<<"5.Delete from end"<<endl;
	cout<<"6.Delete from given index"<<endl;
	cout<<"7.Display"<<endl;
	cout<<"8.Exit"<<endl;
	while(1){
		int c;
		cout<<"Enter choice:";
		cin>>c;
		if(c==1){
			int d;
			cout<<"Enter the data:";
			cin>>d;
			insertatfront(head,tail,d);
		}
		else if(c==2){
			int d;
			cout<<"Enter the data:";
			cin>>d;
			insertatend(head,tail,d);
		}
		else if(c==3){
			int d;
			cout<<"Enter the data:";
			cin>>d;
			int p;
			cout<<"Enter the index:";
			cin>>p;
			insertatpos(head,tail,d,p);
		}
		else if(c==4){
			deletefromfront(head,tail);
		}
		else if(c==5){
			deletefromend(head,tail);
		}
		else if(c==6){
			int p;
			cout<<"Enter the index:";
			cin>>p;
			deletefrompos(head,tail,p);
		}
		else if(c==7){
			display(head);
		}
		else if(c==8){
			cout<<"Exiting...."<<endl;
			return 0;
		}
		else{
			cout<<"Wrong Choice!"<<endl;
		}
	}
}