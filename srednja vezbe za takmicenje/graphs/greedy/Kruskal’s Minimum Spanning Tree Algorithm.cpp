#include<iostream>
#include<algorithm>
using namespace std;

struct Edge{
	int source;
	int destination;
	int weigth;
};

struct Subset{
	int parent;
	int rank;
};

bool cmp(Edge a, Edge b){
	return a.weigth < b.weigth;
}

Edge graph[100];
Subset array[100];
Edge MST[100];
int V,E,n,counter;
int x,y,xroot,yroot;

int find(int broj){
	if(array[broj].parent != broj) return find(array[broj].parent);
	return array[broj].parent;
}

void Union(int x, int y){
	xroot = find(x);
	yroot = find(y);
	
	if (array[xroot].rank < array[yroot].rank) array[yroot].parent = xroot;
	else if (array[xroot].rank > array[yroot].rank) array[xroot].parent = yroot;
	else {
		array[xroot].parent = yroot;
		array[yroot].rank++;	
	} 
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> V >> E;
	for(int i = 0; i<E; i++) cin >> graph[i].source >> graph[i].destination >> graph[i].weigth;
	sort(graph,graph + E, cmp);
	n = 1; MST[0] = graph[0]; counter = 1;
	for(int i = 0; i< V; i++){
		array[i].parent = i;
		array[i].rank = 0;
	}
	while(n != V && counter != E){
		MST[n] = array[counter];
		
		for(int i = 0; i<=n; i++){
			x = find(x); y = find(y);
			if(x == y) break;
			Union(x,y);
			n++;  
		}
		counter++;
	}
	for(int i = 0; i< n; i++) cout << MST[i].destination << ' ' << MST[i].source << ' ' << MST[i].weigth ;
}
