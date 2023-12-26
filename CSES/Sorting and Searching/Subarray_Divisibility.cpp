// 100% CORRECT
#include<iostream>
#include<unordered_map>
using namespace std;

typedef unsigned long long ull;
unordered_map<long long, int> mp;
unordered_map<long long, int>::iterator it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, sol = 0, Sum = 0, X;

    cin >> n;
    mp.reserve(n * 2 + 2);
    mp[0ll]++;
    for (int i = 0; i < n; i++)
    {
        cin >> X;
        Sum += X;

        it = mp.find(Sum % n);
        if (it != mp.end()) sol += it->second;
        
        it = mp.find((Sum % n) - n);
        if (it != mp.end()) sol += it->second;
        
        it = mp.find((Sum % n) + n);
        if (it != mp.end()) sol += it->second;

        mp[Sum % n]++;
    }
    cout << sol;
    return 0;
}
