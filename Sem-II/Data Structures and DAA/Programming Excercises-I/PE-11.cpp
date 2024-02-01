#include<iostream>
using namespace std;

void reversearr(int *arr,int i,int n){
	//base case
	if(i>=n){
		return;
	}
	//recursive case
	swap(arr[i],arr[n]);
	reversearr(arr,i+1,n-1);
}
int main(){
	int n;
	cout<<"Enter the nummber of element in array:";
	cin>>n;
	int arr[n];
	cout<<"Enter elements of the array:";
	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		arr[i]=j;
	}
	int i=0;
	reversearr(arr,i,n-1);
	cout<<"Reversed Array:";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<' ';
	}
	cout<<endl;
	return 0;
}