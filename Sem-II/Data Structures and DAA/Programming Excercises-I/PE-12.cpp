#include<iostream>
using namespace std;
#define N 20
int Q[N],Pr[N];
int r=-1,f=-1; 
void enqueue(int data,int p){
	int i;
	if((f==0)&&(r==N-1)){
		cout<<"Queue Overflow";
	}
	else{
		if(f==-1){ //Empty Queue
			f=r=0;
			Q[r]=data;
			Pr[r]=p;
			cout<<"Element Added"<<endl;
		}
		else if(r==N-1){ //And front > 0
			for(i=f;i<=r;i++){ 
				Q[i-f]=Q[i]; 
				Pr[i-f]=Pr[i]; 
				r=r-f; 
				f=0; 
				for(i=r;i>f;i--){
					if(p>Pr[i]){
						Q[i+1]=Q[i];
						Pr[i+1]=Pr[i];
					}
					else{
						break;
					}
					//i+1 because after leaving loop i decreases by 1
					Q[i+1]=data;
					Pr[i+1]=p;
					r++;
				}
			}
			cout<<"Element Added"<<endl;
		}
		else{
			for(i=r;i>=f;i--){
				if(p>Pr[i]){
					Q[i+1]=Q[i];
					Pr[i+1]=Pr[i];	
				}
				else{
					break;
				}
			}
			Q[i+1] = data;
			Pr[i+1] = p;
			r++;
			cout<<"Element Added"<<endl;
		}	
	}

}
void dequeue(){
	if(f==-1){
		cout<<"Queue Underflow!"<<endl;
	}	
	else{
		cout<<"Element deleted (of highest priority):"<<Q[f]<<endl;
		if(f==r){
			f=r=-1;
		}
		else{
			f++;
		}
	}
}
int main(){
	cout<<"1.Add element"<<endl;
	cout<<"2.Delete Element"<<endl;
	cout<<"3.Exit"<<endl;
	while(1){
		int c;
		cout<<"Enter choice:";
		cin>>c;
		if(c==1){
			int d,p;
			cout<<"Enter Data:";
			cin>>d;
			cout<<"Enter Priority:";
			cin>>p;
			enqueue(d,p);
		}
		else if(c==2){
			dequeue();
		}
		else if(c==3){
			cout<<"Exiting..."<<endl;
			return 0;
		}
		else{
			cout<<"Wrong Input!"<<endl;
		}
	}
}