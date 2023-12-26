// CHECK CSES SHORTEST PATHS1 for more optimized solution
#include<iostream>
using namespace std;

int V = 9;
int graph[9][9] = {     { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
};
bool SptSet[9];
int dist[9];

int MinDistance(){
	int min = INT_MAX, min_index;
	for(int i = 0; i<V; i++) if(!SptSet[i] && dist[i]<=min){
		min = dist[i];
		min_index = i;
	}
	return min_index;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i = 0; i<V; i++) dist[i] = INT_MAX;
	// source is zero here
	dist[0] = 0;
	for(int i = 0; i<V-1; i++) {
		int u = MinDistance();
		SptSet[u] = true;															   // dist[u] + graph[u][j] is distance from source, dist[u] is from sorce to current smallest, graph will be distance from curent smallest to j
		for(int j = 0; j<V; j++) if(graph[u][j] && !SptSet[j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) dist[j] = dist[u] + graph[u][j]; // dist[j] is current smallest distance for this vertex
	}
	for(int i = 0; i < V; i++) cout << i << ' ' << dist[i] << endl;
}
