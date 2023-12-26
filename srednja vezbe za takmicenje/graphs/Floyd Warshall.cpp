#include<iostream>
using namespace std;

const int V = 4;// 4 vertices
#define INF 99999

int graph[V][V] = { {0, 5, INF, 10},  
                    {INF, 0, 3, INF},
                    {INF, INF, 0, 1},
                    {INF, INF, INF, 0}};
int dist[V][V];

void FloydWarshall(){
	for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) dist[i][j] = graph[i][j];
	for (int v = 0; v < V; v++) // for every vertex update adjacent vertices
		for (int src = 0; src < V; src++) // source vertex
			for (int dest = 0; dest < V; dest++) // destination vertex
				 if (dist[src][v] + dist[v][dest] < dist[src][dest]) dist[src][dest] = dist[src][v] + dist[v][dest];
				// if path from source to dest is larger then going from source to v vertex and then to dest change path distance
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++) if (!(dist[i][j] == INF))cout << dist[i][j] << ' ';
									else cout << "INF ";
		cout << endl;
	}
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	FloydWarshall();
	
}
