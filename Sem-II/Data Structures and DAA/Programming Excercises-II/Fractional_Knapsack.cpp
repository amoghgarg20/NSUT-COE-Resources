// O(nlogn) time complexity due to sorting(most time consuming)
#include <bits/stdc++.h>
using namespace std;

struct Item{
	int value, weight;

	Item(int v,int w){
	value=v;
	weight=w;
	}
};
// Comparison function to sort Item according to value/weight ratio
bool cmp(struct Item a, struct Item b){
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int n){
	// Inbuilt sorting of Item on basis of ratio
	sort(arr, arr + n, cmp);
	int cur=0; 
	double ans=0.0; 
	for (int i = 0; i < n; i++){
		if (cur + arr[i].weight <= W) {
			cur += arr[i].weight;
			ans += arr[i].value;
		}
		else {
			int remain = W - cur;
			ans += arr[i].value*((double)remain/(double)arr[i].weight);
			break;
		}
	}
	return ans;
}
int main(){
	int W = 50;
	Item arr[]={ { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum value = "<< fractionalKnapsack(W, arr, n);
	return 0;
}
