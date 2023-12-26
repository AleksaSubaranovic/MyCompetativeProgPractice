#include<iostream>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int>* adj;
	void DFSutil(int v, bool visited[]){
		if (!visited[v]){
			visited[v] = true;
			cout << v << ' ';
			for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++) DFSutil(*it, visited);
		}
	}
	public:
		Graph(int V) : V(V){
			adj = new list<int>[V];
		}
		// directed
		void addEdge(int v, int u){
			adj[v].push_back(u);
		}
		void DFS(int source){
			bool visited[V];
			for (int i = 0; i < V; i++) visited[i] = false;
			DFSutil(source, visited);
		}
};

Graph g(4);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	 g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);
	g.DFS(1);
	return 0;
}
