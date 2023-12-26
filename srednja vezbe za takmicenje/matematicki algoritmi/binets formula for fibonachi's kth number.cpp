#include<iostream>
#include<cmath>
using namespace std;

int a;
// first is 1, second is 1, third is 2
// if first is zero special case for zero needed
// and use n+1
long long Binets(int n){
	return pow(3.2360679775/2, n)/2.2360679775;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> a;
	cout << Binets(a);
	return 0;
}
