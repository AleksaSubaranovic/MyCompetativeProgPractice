#include<iostream>
using namespace std;
int V = 5;
int graph[5][5] = { 	{ 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } }; 

int parent[5];
int key[5];
bool mstSet[5];

// returns index of minimum key vertex
int minKey(){
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; i++) if(mstSet[i] == false && key[i]<min){
		min = key[i];
		min_index = i;
	}
	return min_index;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for (int i = 0; i < V; i++){
		key[i] = INT_MAX;
		mstSet[i] = false;
	}
	key[0] = 0;
	parent[0] = -1; // first node is root
	for(int i = 0; i< V-1; i++){
		int u = minKey(); // minKey returns index of vertex with min key value
		mstSet[u] = true; // so we dont use this vertex again
		for(int j = 0;j<V;j++) if(graph[u][j] && !mstSet[j] && graph[u][j] < key[j]) parent[j] = u, key[j] = graph[u][j];
	}
	  for(int i = 0; i<V; i++) cout << parent[i] << ' ' << graph[i][parent[i]];        
}
