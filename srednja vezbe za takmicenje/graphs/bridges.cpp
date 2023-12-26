#include<iostream>
#include<list>
#define IT (*it)
using namespace std;

class Graph{
	int V;
	list<int>* adj;
	void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]){
		static int time = 0;
		visited[v] = true;
		disc[v] = low[v] = ++time;
		for (auto it = adj[v].begin(); it != adj[v].end(); it++)
			if (!visited[IT]){
				parent[IT] = v;
				bridgeUtil(IT,visited,disc,low,parent);
				low[v] = min(low[v], low[IT]);
				
				if (low[IT] > disc[v]) cout << v << IT << endl; // if id given to edge vertex IT is greater means there is no back edge cause it only increased
			}													// would decrease if there was back edge
			else if (IT != parent[v]) low[v] = min(low[v], disc[IT]);
	}
	public:
		Graph(int V) : V(V){
			adj = new list<int>[V];
		}
		void addEdge(int v, int u){
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		void bridges(){
			bool visited[V];
			int disc[V];
			low[V];
			int parent[V];
			for (int i = 0; i < V; i++) visited = false, parent[i] = -1;
			for (int i = 0; i < V; i++) if (!visited[i]) brigdeUtil(i, visited, disc, low, parent);
		}
		
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	return 0;
}
