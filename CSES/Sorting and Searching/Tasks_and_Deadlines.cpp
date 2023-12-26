// 100% CORRECT
#include<iostream>
#include<map>
using namespace std;

typedef unsigned long long ull;

pair<ull, ull> p[(int)2e5];
multimap<ull, ull> mp;
ull currTime;
long long rewards;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    for (int i = 0; i < n; i++) mp.emplace(p[i]);
    
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        currTime += it->first;
        rewards += it->second - currTime;
    }
    cout << rewards;
    return 0;
}
