#include<iostream>
#include<list>
#include<stack>
#define IT (*it)
using namespace std;

class Graph{
	list<int>* adj;
	int V;
	void TopSortUtil(int v, bool visited[], stack<int>& s){
		visited[v] = true;
		for (auto it = adj[v].begin(); it != adj[v].end(); it++) if (!visited[IT]) TopSortUtil(IT, visited, s);
		s.push(v);
	}
	public:
		Graph(int V) : V(V){
			adj = new list<int>[V];
		}
		void addEdge(int v, int u){
			adj[v].push_back(u);
		}
		void TopSort(){
			stack<int> s;
			bool visited[V];
			for (int i = 0; i < V; i++) visited[i] = false;
			for (int i = 0; i < V; i++) if (!visited[i]) TopSortUtil(i,visited,s);
			while (!s.empty()) cout << s.top() << ' ', s.pop();
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
	
	g.TopSort();
	
	return 0;
}
