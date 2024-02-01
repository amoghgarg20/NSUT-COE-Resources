#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Queue{
	int *arr;
	int f; //front
	int n; //Maximum size of queue
	int e; //End
	int cs;//Current Size

public:
	Queue(int s){
		n=s;
		arr=new int[n];
		f=0;
		e=n-1;
		cs=0;	
	}
	void enqueue(int d){
		if(cs<n){
		e=(e+1)%n;
		arr[e]=d;
		cs++;
		}
		else{
			cout<<"Queue is full--> Overflow"<<endl;
		}		
	}
	void dequeue(){
		if(cs>0){
		f=(f+1)%n;
		cs--;
		}
		else{
			cout<<"Queue is empty--> Underflow"<<endl;
		}
	}
	int front(){
		return arr[f];
	}
	bool empty(){
		return cs==0;	
	}
};
int main(){
	cout<<"Enter the size of the queue:";
	int n;
	cin>>n;
	Queue q(n);
	cout<<"Menu"<<endl;
	cout<<"1.Add element in the queue"<<endl;
	cout<<"2.Delete element from the queue"<<endl;
	cout<<"3.Check whether queue is empty or not"<<endl;
	cout<<"4.Exit->Print element of queue on standard output and store elements in the file"<<endl;
	while(1){
		int c;
		cout<<"Enter your choice:";
		cin>>c;
		if(c==1){
			int d;
			cout<<"Enter element you want to add to the queue:";
			cin>>d;
			q.enqueue(d);
			cout<<"Element added"<<endl;
		}
		else if(c==2){
			q.dequeue();
			cout<<"Element deleted"<<endl;
		}
		else if(c==3){
			if(q.empty()){
				cout<<"The queue is empty"<<endl;
			}
			else{
				cout<<"The queue is not empty"<<endl;
			}
		}
		else if(c==4){
			string s;
			cout<<"Enter the name of file in which you want to write elements:";
			cin>>s;
			ofstream fout;
			fout.open(s);
			while(!q.empty()){
				cout<<q.front()<<" ";
				fout<<q.front()<<endl;
				q.dequeue();
			}
			cout<<endl;
			fout.close();
			cout<<"Ending Program...";
			return 0;
		}
		else{
			cout<<"Wrong input!"<<endl;
		}
	}


	return 0;
}