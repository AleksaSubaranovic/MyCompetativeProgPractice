#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int H[100000];
int min_index, max_index;
int n;
int L,D;
long long rez;
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> H[i];
		if (H[min_index]>H[i]) min_index = i;
		if (H[max_index]<H[i]) max_index = i;
	}
	L = -1;
	D = -1;
	for (int i = 0; i < n; i++){
		if (L < i){
			L++;
			while (L < n && H[min_index] != H[L]) L++;
		}
		if (D < i){
			D++;
			while (D < n && H[max_index] != H[D]) D++;
		}
		if (L == n || D == n) break;
		rez += n - max(L,D); // zbog uslova if (L<i) i if (D<i) za svako i pre levog indeksa povecace se rezultat za n-max(L,D) sto je isto sto i (l+1)*(n-d)
	}
	cout << rez;
	
}
