//Time Complexity is O(V^2)
#include <bits/stdc++.h>
using namespace std;
#define V 5

int minKey(int key[], bool mstSet[]){
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}
void print(int parent[], int graph[V][V]){
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<endl;
}
void prim(int graph[V][V]){
	// Array to store constructed MST
	int parent[V];
	int key[V];
	// To represent set of vertices included in MST
	bool mstSet[V];
	for (int i = 0; i < V; i++){
		key[i] = INT_MAX, mstSet[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < V - 1; count++){
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	print(parent, graph);
}
int main(){
	int graph[V][V]={0};
	ifstream f;
	f.open("inp.txt");
	string line;
	while(getline(f,line)){
		vector<int> temp;
		stringstream lineStream(line);
		int value;
		while(lineStream >> value){
			temp.push_back(value);
		}
		graph[temp[0]][temp[1]]=temp[2];
	}
	prim(graph);
	return 0;
}
