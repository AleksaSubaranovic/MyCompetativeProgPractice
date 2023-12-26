#include<iostream>
#include<list>
using namespace std;

int V;
list<int>* graph;

void addEdge(int v, int w){
	graph[v].push_back(w);
	graph[w].push_back(v);
}

// E. Path is when every edge is visited once
// E. Cycle is when u start at one vertex and finish at same vertex and visits every edge once

// DFS graph to set vertices to true if there is edge to between them 
void DFSUtil(int v, bool visited[]){
	visited[v] = true;
	for(list<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++)
		if (!visited[*it]) DFSUtil(*it, visited);
}

// check if all non zero degree vertices are connected using DFS
bool isConnected(){
	bool visited[V];
	int i;
	for (i = 0; i<V; i++) visited[i] = false;
	for (i = 0; i<V; i++) if (graph[i].size()) break; // find first vertex with non zero degree
	
	if (i == V) return true; // return true if there is no edges 
	
	// start DFS traversal from vertex with non zero degree
	DFSUtil(i,visited);
	
	// check if all non zero degree vertices are visited
	for (i = 0; i<V; i++) if (!visited[i] && graph[i].size()) return false; // returns false if there is zero degree vertex
	return true; 
}

int IsEulerian(){
	// check if all non zero degree vertices are connected
	if (!isConnected()) return 0;
	
	int odd = 0; // cound odd degree vertices
	for (int i = 0; i<V; i++) if (graph[i].size() & 1) odd++; // if true its odd number
	// if there is 2+ odd degree vertices then there is no Eulerian
	if (odd > 2) return 0;
	// if 1 then there is Eulerian path
	// if 2 then tehre is Eulerian cycle
	return (odd)? 1 : 2; 
}

void Test(){
	int rez = IsEulerian();
	if (!rez) cout << "NOPE";
	else if (rez == 1) cout << "Path";
	else cout << "Cycle";
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> V; // 5
	graph = new list<int>[V];
	addEdge(1, 0);
	addEdge(0, 2);
	addEdge(1, 2);
	addEdge(3, 0);
	addEdge(4, 3);
	Test();
	
}
