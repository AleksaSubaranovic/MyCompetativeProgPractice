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
		// undirected
		void addEdge(int v, int u){
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		void PrintConnectedNodes(){
			bool visited[V];
			for (int i = 0; i < V; i++) visited[i] = false;
			for (int i = 0; i < V; i++) DFSutil(i, visited), cout << endl;
		}
};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	Graph g(5); // 5 vertices numbered from 0 to 4 
    g.addEdge(1, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.PrintConnectedNodes();
	
	return 0;
}
