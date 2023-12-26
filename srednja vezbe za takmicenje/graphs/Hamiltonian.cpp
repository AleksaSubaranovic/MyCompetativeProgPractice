#include<iostream>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int>* adj;
	public:
		Graph(int V) : V(V){
			adj = new list<int>[V];
		}
		void addEdge(int v, int u){
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
	private:
		bool isSafe(int v, int path[], int pos){
			for (int i = 0; i <= pos; i++) if (i == v) return false;
			bool cond = false;
			for (auto it = adj[pos - 1].begin(); it != adj[V-1].end(); it++) if ((*it) == v) {
				cond = true;
				break;	
			}
			return cond;
		}
		bool hamCycleUtil(int path[], int pos){
			// if all vertices are included in path
			if (pos == V){
				for (auto it = adj[V-1].begin(); it != adj[V-1].end(); it++) if (!(*it)) return true;
				return false;
			}
			for (int i = 1; i < V; i++) if (isSafe(i, path, pos)) {
				path[pos] = i;
				if (hamCycleUtil(path, pos + 1)) return true;
				path[pos] = -1;
			}
		}
	public:					
		
		void HamCycle(){
			int path[V];
			for (int i = 1; i < V; i++) path[i] = -1;
			path[0] = 0;
			if (!hamCycleUtil(path, 1)){
				for (int i = 0; i < V; i++) cout << path[i] << ' ';
				cout << path[0] << endl;
			}
		}
		
};




// Hamiltonian Path visits every vertex once, Cycle has edge between starting and ending vertex

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	return 0;
}
