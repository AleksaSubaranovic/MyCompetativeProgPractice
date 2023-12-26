// 100% CORRECT
#include<iostream>
#include<unordered_map>
using namespace std;
 
typedef unsigned long long ull;

unordered_map<long long, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t; long long res = 0; int X; long long Sum = 0;
    cin >> n >> t; mp.reserve(2*n); // maybe can reserve only n
    for (int i = 0; i < n; i++)
    {
        mp[Sum]++;
        cin >> X;
        Sum += X;
        auto it = mp.find(Sum - t);
        if (it != mp.end()) res += it->second;
    }
    cout << res;
    return 0;
}