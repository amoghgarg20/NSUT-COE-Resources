#include <bits/stdc++.h>
using namespace std;
#define V 4
void printSolution(int dist[][V]){
	cout << "The following matrix shows the shortest distances between every pair of vertices \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INT_MAX)
				cout << "INF"<< "	 ";
			else
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
}
void floydWarshall(int graph[][V]){
	int dist[V][V], i, j, k;
	for (i = 0; i < V; i++){
		for (j = 0; j < V; j++){
			dist[i][j] = graph[i][j];
		}
	}
	for (k = 0; k < V; k++) {
		// Pick all vertices as source one by one
		for (i = 0; i < V; i++) {
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < V; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INT_MAX && dist[i][k] != INT_MAX)){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	printSolution(dist);
}
int main(){
	int graph[V][V] = { { 0, 5, INT_MAX, 10 },
						{ INT_MAX, 0, 3, INT_MAX },
						{ INT_MAX, INT_MAX, 0, 1 },
						{ INT_MAX, INT_MAX, INT_MAX, 0 } };
	floydWarshall(graph);
	return 0;
}
