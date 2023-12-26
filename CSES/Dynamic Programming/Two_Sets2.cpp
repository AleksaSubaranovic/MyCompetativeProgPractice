// 100% CORRECT
#include<iostream>
using namespace std;

typedef unsigned long long ull;
#define MOD 1000000007ll
long long dp[62626];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int maxi = (n * (n + 1)) / 2;
    if (maxi & 1) { cout << 0; return 0; }
    maxi /= 2;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = maxi; j >= i; j--) dp[j] = (dp[j] + dp[j - i]) % MOD;
    }
    cout << dp[maxi] * (MOD + 1) / 2ll % MOD; // no idea at the moment why MOD + 1 is needed, result stays same with it
    return 0;
}
