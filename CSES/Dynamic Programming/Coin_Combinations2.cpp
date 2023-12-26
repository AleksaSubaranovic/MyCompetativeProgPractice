// 100% CORRECT
#include<iostream>
using namespace std;

typedef unsigned long long ull;

#define MOD 1000000007

int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    dp[0] = 1;
    while (n--)
    {
        int a;
        cin >> a;
        for (int i = a; i <= x; i++)
        {
            dp[i] = (dp[i] + dp[i - a]) % MOD;
        }
    }
    cout << dp[x];
    return 0;
}
