#include<iostream>
using namespace std;

class Stack{
	int *arr;
	int top;
	int n;
public:
	Stack(int s){
		n=s;
		arr=new int[n];
		top=-1;
	}
	void push(int d){
		if(top<n-1){
			top++;
			arr[top]=d;
		}
		else{
			cout<<"Stack Overflow"<<endl;
		}
	}
	void pop(){
		if(top>=0){
			top--;
		}
		else{
			cout<<"Stack Underflow"<<endl;
		}
	}
	bool empty(){
		if(top>=0){
			return false;
		}
		return true;
	}
	void display(){
		cout<<"The Stack elements are:";
		for(int i=0;i<=top;i++){
			cout<<arr[top]<<' ';
		}
		cout<<endl;
	}
	int size(){
		return top+1;
	}
	int topmost(){
		return arr[top];
	}
};
int main(){
	cout<<"Enter the size of the stack:";
	int n;
	cin>>n;
	Stack s(n);
	cout<<"Menu"<<endl;
	cout<<"1.Push element in the stack"<<endl;
	cout<<"2.Pop element from the stack"<<endl;
	cout<<"3.Check whether stack is empty or not"<<endl;
	cout<<"4.Display the top most element of stack"<<endl;
	cout<<"5.Display current size of stack"<<endl;
	cout<<"6.Exit and display the characters of stack"<<endl;
	while(1){
		int c;
		cout<<"Enter your choice:";
		cin>>c;
		if(c==1){
			int d;
			cout<<"Enter element you want to push in the stack:";
			cin>>d;
			s.push(d);
		}
		else if(c==2){
			s.pop();
			cout<<"Element removed"<<endl;
		}
		else if(c==3){
			if(s.empty()){
				cout<<"Stack is empty"<<endl;
			}
			else{
				cout<<"Stack is not empty"<<endl;
			}

		}
		else if(c==4){
			cout<<"Top most element of stack is:"<<s.topmost()<<endl;
		}
		else if(c==5){
			cout<<"Current size of stack is:"<<s.size()<<endl;
		}
		else if(c==6){
			cout<<"Elements of stack from top to bottom:";
			while(!s.empty()){
				cout<<s.topmost()<<" "<<endl;
				s.pop();
			}
			cout<<"Exiting..."<<endl;
			return 0;
		}
		else {
			cout<<"Wrong Input!"<<endl;
		}	
	}
	return 0;
}