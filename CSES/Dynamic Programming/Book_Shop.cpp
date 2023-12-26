// 100% CORRECT
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;

pair<int, int>p[1000];
int dp[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> p[i].first;
    for (int i = 0; i < n; i++) cin >> p[i].second;

    for (int i = 0; i < n; i++) // must check every pair
    {
        for (int j = x; j >= p[i].first; j--) // order does matter
        {
            dp[j] = max(dp[j], dp[j - p[i].first] + p[i].second);
        }
    }
    cout << dp[x];
    return 0;
}

