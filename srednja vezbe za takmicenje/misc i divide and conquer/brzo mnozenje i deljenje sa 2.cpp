#include<iostream>
using namespace std;

int n;

main(){
	ios::sync_with_stdio(false);
	cin >> n;
	// multiply
	n = n << 1;
	cout << n;
	// divide
	n = n >> 1;
	n = n >> 1;
	cout << ' ' << n;
}
