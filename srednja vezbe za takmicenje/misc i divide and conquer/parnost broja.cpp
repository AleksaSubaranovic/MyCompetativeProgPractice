#include<iostream>
using namespace std;

int n;

main(){
	ios::sync_with_stdio(false);
	cin >> n;
	if(n & 1) cout << "neparan"; // 5 = 101, 1 = 001 AND 101 001 == 001
	else cout << "paran";
}
