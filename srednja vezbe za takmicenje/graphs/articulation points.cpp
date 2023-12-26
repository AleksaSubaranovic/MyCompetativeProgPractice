// articulation points 
#include<iostream>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int>* adj;
	#define IT (*it)
		void APUtil(int v, bool visited[], int disc[], int low[], bool ap[], int parent[]){
				static int time = 0;
				int children = 0;
				visited[v] = true;
				disc[v] = low[v] = ++time;
				for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
					if (!visited[IT]){
						children++, parent[IT] = v;
						APUtil(IT,visited,disc,low,ap,parent);
						low[v] = min(low[v], low[IT]);
						
						if (parent[v] == -1 && children > 1) ap[v] = true; // if v is root and has 2 or more children then it is AP
						if (parent[v] != -1 && low[IT] >= disc[v]) ap[v] = true; // if v is not root and if its child is greater than discovery time of v
					}
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
		void AP(){
			bool visited[V]; // visited bool array
			int disc[V]; // discovery times of vertices
			int low[V]; // lowest discovery times for parent node
			int parent[V]; // parent vertices
			bool ap[V]; // articulation points
			int time = 0;
			for (int i = 0; i < V; i++) visited[i] = ap[i] = false, parent[i] = -1;
			
			for (int i = 0; i < V; i++) if (!visited[i]) APUtil(i,visited,disc,low,ap,parent);
			for (int i = 0; i < V; i++) if (ap[i]) cout << i << ' ';
			
		}
};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	  // Create graphs given in above diagrams 
    cout << "\nArticulation points in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.AP(); 
  
    cout << "\nArticulation points in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.AP(); 
  
    cout << "\nArticulation points in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.AP(); 
  
    return 0;
	return 0;
}
