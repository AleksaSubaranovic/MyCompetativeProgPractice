#include<iostream>
using namespace std;

struct Edge{
	int source,destination;
};
// in array of subsets index is the value of first element of this subset
struct subset{
	int parent; // parent is originaly same as index while it is its own parent
	int rank; // rank is used for rooting elements, once there is element with rank it means it is root of other elements,higher rank means more roots
};

int V,E;// V = Vertices(numbers from 0 to V-1), E = number of edges
Edge* edge_array;
subset* subset_array;

// finds parent
// returns parent of element, root of set, recursive solution
int find(int i){ 
	if (subset_array[i].parent != i) return find(subset_array[i].parent);
	return subset_array[i].parent; // or return i
}

// makes union of 2 sets
void Union(int x, int y){
	int xroot = find(x);
	int yroot = find(y);
//	cout << xroot << ' ' << yroot << endl;
	// attach smaller rank to higher
	if(subset_array[xroot].rank < subset_array[yroot].rank) subset_array[xroot].parent = yroot;
	else if(subset_array[xroot].rank > subset_array[yroot].rank) subset_array[yroot].parent = xroot;
	else {
		// if same rank attach yroot to xroot
		subset_array[yroot].parent = xroot;
		subset_array[xroot].rank++;
	}
	
}

bool isCycle(){
	// initalize subset values
	subset_array = new subset[V];
	for(int i = 0;i<V;i++){
		subset_array[i].parent = i;
		subset_array[i].rank = 0;
	}
	for(int i = 0; i<E;i++){
		int x = find(edge_array[i].source);
		int y = find(edge_array[i].destination);
		
		if(x == y) return true;
		
		Union(x,y);
	}
	return false;
}


main(){
	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin >> V >> E;
	edge_array = new Edge[E];
	for(int i = 0; i<E;i++) cin >> edge_array[i].source >> edge_array[i].destination;
	if (isCycle()) cout << "There is Cycle";
	else cout << "There is no Cycle";
}
