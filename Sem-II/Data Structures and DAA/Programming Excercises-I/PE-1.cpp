//Amogh Garg-2020UCO1688
//Data in the file is not sorted
#include<bits/stdc++.h>
using namespace std;
//Linear Search
bool LinearSearch(int *lsarr,int i,int k){
	for(int j=0;j<i+1;j++){
		if (lsarr[j]==k){
			return true;
		}	
	}
	return false;

}
//Binary Search
bool BinarySearch(int *bsarr,int s,int e,int k){
	if(s<=e){
		int mid=(s+e)/2;
		if(bsarr[mid]==k){
			return mid;
		}
		else if(bsarr[mid]>k){
			BinarySearch(bsarr,s,mid-1,k);
		}
		else{
			BinarySearch(bsarr,mid+1,e,k);
		}

	}
	return -1;
}
int main(){
	int lsarr[100],bsarr[100],i=0; //Separate arrays->To keep sorted data for Binary Search
	ifstream f;                    //and unsorted for Linear Search
	f.open("inp1.txt");
	int x;
	while(f>>x){
		lsarr[i]=x;
		bsarr[i]=x;
		i++;	
	}
	sort(bsarr,bsarr+i+1);       //Sorting Binary Search array
	int k;
	cout<<"Enter the element to search for:";
	cin>>k;
	//Binary Search Result
	if(BinarySearch(bsarr,0,i,k)!= -1){
		cout<<"Binary Search:Element is present at "<<BinarySearch(bsarr,0,i,k)<<endl;
	}
	else{
		cout<<"Binary Search:Element is not present"<<endl;
	}
	//Linear Serch Result
	if(LinearSearch(lsarr,i,k)){
		cout<<"Linear Search:Element is present"<<endl;
	}
	else{
		cout<<"Linear Search:Element is not present"<<endl;
	}
	return 0;


}