#include<iostream>
using namespace std;

int array[100];
int n;
int i;
int LIS_length, LIS_array[100];

// Binary Search Implementation
// note that recursive call arguments are using med not med+1/-1 counting that we just need r element, med+-1 skips element
// result needs to be equall or first next greater value of the one looked after, can use lower_bound as well
int CeilIndex(int l, int r, int key){
	//cout << l << r;
	if(r>l+1){
		int med = l + (r-l)/2;
		//cout << med << endl;
		if(array[med] == key) return med;
		if (array[med] > key) CeilIndex(l,med,key);
		else CeilIndex(med,r,key);
	}
	else return r;
}


main(){
	// INPUT
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) cin >> array[i]; 
	
	//minimum length
	LIS_length = 1;
	LIS_array[0] = array[0];
	
	// LOOP BODY
	for(i = 0; i<n; i++)
		if(array[i]<LIS_array[0]) LIS_array[0] = array[i]; 								// set minimum value for array
		else if(array[i] > LIS_array[LIS_length-1]) LIS_array[LIS_length++] = array[i]; // add element to array and increment length
		else LIS_array[CeilIndex(0,LIS_length-1,array[i])] = array[i];					// find place for new element with same or closest greater value
	
	// OUPTPU
	cout << LIS_length << endl;
}
