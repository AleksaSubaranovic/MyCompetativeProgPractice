#include<iostream>
#include<algorithm>
using namespace std;

int mouse[100],whole[100];
int n, max_diff;

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 0; i<n; i++) cin >> mouse[i];
	for(int i = 0; i<n; i++) cin >> whole[i];
	sort(mouse,mouse+n);
	sort(whole,whole+n);
	max_diff = whole[0]-mouse[0];
	for(int i = 1; i<n; i++) if (whole[i]-mouse[i] > max_diff) max_diff = whole[i]-mouse[i];
	cout << max_diff;
}
