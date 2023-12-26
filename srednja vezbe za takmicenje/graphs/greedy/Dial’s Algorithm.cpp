#include<iostream>
#include<utility>
#include<list>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;

int V = 9; int W = 14, source = 0;
// graph is matrix where every row to column has weight
list < pair<int, int> > graph[9];// V = 9

void addEdge(int u, int v, int w){
	graph[u].push_back(make_pair(v,w));
	graph[v].push_back(make_pair(u,w));  
}

// Buckets is array of lists one for every weight, where list per weight has vertexes whose distance from source is that weight
list<int>Buckets[14*9-1];// W*V-1

// distance list, dist[i].first is distance from source to vertex i, d[i].second is iterator to vertex i in bucket
vector<pair<int, list<int>::iterator> > dist(V);

main(){
//	ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	addEdge(0, 1, 4); 
    addEdge(0, 7, 8); 
    addEdge(1, 2, 8); 
    addEdge(1, 7, 11); 
    addEdge(2, 3, 7); 
	addEdge(2, 8, 2); 
    addEdge(2, 5, 4); 
    addEdge(3, 4, 9); 
    addEdge(3, 5, 14); 
	addEdge(4, 5, 10); 
	addEdge(5, 6, 2); 
    addEdge(6, 7, 1); 
    addEdge(6, 8, 6); 
    addEdge(7, 8, 7); 
    
    // set distance values as INF 
    for(int i = 0; i<V; i++) dist[i].first = INF;
    Buckets[0].push_back(source);
	dist[source].first = 0; 
    int index = 0;
    
    while(index != W*V){
    	while(Buckets[index].size() == 0 && index < W*V) index++; // find first non empty bucket
    	
    //	if(index == W*V) break;
    	
    	int u = Buckets[index].front(); // u is first vertex with weight from src to u equall to index
    	Buckets[index].pop_front(); // remove this vertex
    	
    	for(auto i = graph[u].begin(); i != graph[u].end(); ++i){ // begin and end return iterators
    		
			int v = (*i).first; // v is vertex from graph that U has edge with
    		int weight = (*i).second; // weight is between v and u
    		int du = dist[u].first;
    		int dv = dist[v].first;
    		// if distance from source to v is greater then distance from source to u with distance between u and w 
			// then faster route is to go from source to u then to v
    		if(dv > du + weight){
    			// check if distance is INF(only first time this vertex is used)
    			if(dv != INF) Buckets[dv].erase(dist[v].second); // if there is faster route then delete previous by removing that vertex from Bucket with current weight
    			// dist[v].second is iterator to vertex in this bucket
    			
    			// update values
				dist[v].first = du + weight;
    			dv = dist[v].first;
    			Buckets[dv].push_front(v);
    			//update iterators
    			dist[v].second = Buckets[dv].begin();
    			cout << "sdasdasd";
			}
		}
	}
	for(int i = 0; i<V;i++) cout << i << ' ' << dist[i].first<<endl;
}
