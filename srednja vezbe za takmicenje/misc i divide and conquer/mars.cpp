#include<iostream>
#include<algorithm>
using namespace std;

// 

int niz[4];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	cin >> niz[0] >> niz[1] >> niz[2] >> niz[3];
	/*
	cout << abs(niz[0]+niz[3]-niz[1]-niz[2]+1)/2;
*/
	sort(niz,niz+4);
	cout << abs(niz[3]+abs(niz[2]-niz[1]+1)/2) - abs(niz[2] + abs((niz[3]-niz[0]+1))/2);
	return 0;
}
