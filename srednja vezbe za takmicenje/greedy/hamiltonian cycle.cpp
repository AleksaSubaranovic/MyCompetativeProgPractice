#include<iostream>
using namespace std;

int V = 5;
bool graph[10][10] = {
						{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}
}; // graph[i][j] == 1 if there is direct edge from i to j
int path[5] = {-1,-1,-1,-1,-1};

bool isSafe(int i, int pos){ // checking pos-1 to i in matrix if there is edge, edge between last added vertex to path and i vertex
	if (!graph[path[pos-1]][i]) return false; // if there isn't edge return false
	for(int j = 0; j < pos; j++) if (path[j] == i) return false; // if there is edge check if this vertix was included before 
	return true;
}

bool HamCycle(int pos){
	if(pos == V){ // when array is formed
		return graph[path[pos-1]][0]; // check if there is edge form last element of path and first element of path, so we know there is cycle
	}
	for(int i = 1; i<V; i++){
		if(isSafe(i,pos)){ // check if it is safe to set vertex i as next position
			path[pos] = i;
			if (HamCycle(pos+1)) return true; // recursive call
			path[pos] = -1; // if vertex i was not correct choice change it and redo for loop for next vertex
		}
	}
	return false;
}
// recursion goes from vertex 1 and adds it to path if it is safe and repeats
// generating combination of all paths ending with first correct one and using isSafe condition we are sure that path is correct
// if current recursion ended with no edge or ended up being wrong then combination of diffrent order will be tried out


main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	path[0] = 0;
	if(HamCycle(1)){
		for(int i = 0; i<V; i++) cout << path[i] << ' ';
		cout << path[0];
	}
	else cout << "Doesn't exist";
	
}
