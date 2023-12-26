#include<iostream>
#include<queue>
using namespace std;

struct item{
	float weight;
	int value;
};

struct Node{
	int index; // index of array
	int profit; // profit from all root node to this node with this node
	int bound; // upper bound of maximum profit of this subtree of this node
	float weight;
};

bool cmp(item i1, item i2){
	double r1 = (double)i1.value/i1.weight;
	double r2 = (double)i2.value/i2.weight;
	return  r1>r2;
}

// returns bound of profit for subtree of u
int Bound(Node u, int n, int W, item array){
	
	if(u.weight >= W) return 0; // if weight is larger then max weight return zero
	int profit_bound = u.profit; // profit bound is set as current profit
	int i = u.index + 1; // set counter as 1 + current
	float totweight = u.weight;
	
	// index condition and knapsack capacity conditions
	while((i < n &&  totweight + array[i].weight <= W){
		totweight += array[i].weight;
		profit_bound += array[i].value;
		i++; 
	}
	
	// if counter wasn't finished add fraction of last item for maximum bound on subtree
	if(i < n) profit_bound += (w - totweight) * array[i].value/array[i].weight;
	
	return profit_bound;
}

int Knapsack(int W, item array[], int n){
	
	sort(array, array+n, cmp);
	
	queue<Node> q;
	Node u, v;
	u.index = -1;
	u.profit = 0;
	q.push(u);
	
	// loop
	int MaxProfit = 0;
	while(!q.empty()){
		// remove queue element
		u = q.front();
		q.pop();
		
		// if starting node change to 0
		if(u.index == -1) u.index = 0;
		
		// if there is no next element
		if(u.index == n-1) continue;
		
		// v is sum of current and next element
		v.index = u.index+1;
		v.weight = u.weight + array[v.index].weight; 
        v.profit = u.profit + array[v.index].value; 
        
        if(v.weight <= W && v.profit > MaxProfit) MaxProfit = v.profit;
        
        // getting upper bound to see wheter to add v to queue or not
        v.bound = Bound(v,n,W,array);
        // if bound is higher then maxProfit then add it to queue for further consideration
        if(v.bound > maxProfit) q.push(v);
        
        // repeat for element before (without item in knapsack)
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = Bound(v,n,W,array);
        if(v.bound > MaxProfit) q.push(v);
        
	}
	return MaxProfit;
}


main(){
	int W = 10; // max weight
	item array[] = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};
	int n = 5;
	 
}
