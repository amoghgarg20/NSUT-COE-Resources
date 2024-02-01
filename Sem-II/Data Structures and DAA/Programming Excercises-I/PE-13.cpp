#include<iostream>
using namespace std;

void toh(int n,char src,char helper,char dest){
	//Base Case
	if(n==0){
		return;
	}
	//Recursive Case
	toh(n-1,src,dest,helper);
	cout<<"Move Disc-"<<n<<" from "<<src<<" to "<<dest<<endl;
	toh(n-1,helper,src,dest);
}
int main(){
	int n;
	cout<<"Enter the number of discs:";
	cin>>n;
	toh(n,'A','B','C');
	return 0;
}