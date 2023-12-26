#include<iostream>
using namespace std;

int array[4] = { 1, 5, 3, 4};
int n = 4;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	int xor1 = array[0], xor2 = 1;
	for (int i = 1; i < n; i++) xor1 ^= array[i];
	for (int i = 2; i <= n+1; i++) xor2 ^= i;
	cout << xor1 << ' ' << xor2 << ' ' << (xor1^xor2);
	
	return 0;
}
