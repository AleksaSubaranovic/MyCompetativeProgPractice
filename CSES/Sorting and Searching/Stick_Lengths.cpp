// 100% CORRECT
#include<bits/stdc++.h>
using namespace std;
 
#define N 200123
 
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> v(n);
    long long ans = 0;
    for(long long &a : v) cin >> a;
    sort(v.begin(), v.end());
    for(int i = 0 ; i < n ; i++){
        ans += abs(v[n/2]-v[i]);
    }
    cout << ans << endl;
    return 0;
}