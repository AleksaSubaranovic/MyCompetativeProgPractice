#include<iostream>
using namespace std;

struct Edge{
	int src, dest, weight;
};

int V, E;
int source;
Edge* graph;
int* dist;
void BellmanFord(int source){
	for (int i = 0; i<V; i++) dist[i] = INT_MAX;
	dist[source] = 0;
	
	for (int i =0; i<V; i++)
		for (int j = 0; j<E; j++){
			int u = graph[j].src;
			int v = graph[j].dest;
			int weight = graph[j].weight;
			if (dist[u] != INT_MAX && dist[v]+weight < dist[v]) dist[v] = dist[u] + weight;
			
			// check for negative cycles
			for (int i = 0; i<E; i++){
				int u = graph[i].src;
				int v = graph[i].dest;
				int weight = graph[i].weight;
				if (dist[i] != INT_MAX && dist[u]+weight < dist[v]){
					cout << "NEGATIVE CYCLE";
					return;
				}
			}
			for (int i = 0; i<V; i++) cout << dist[i] << ' ';
		}
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> V >> E;
	graph = new Edge[E];
	cin >> source;
	dist = new int[V];
	// add edges
}
