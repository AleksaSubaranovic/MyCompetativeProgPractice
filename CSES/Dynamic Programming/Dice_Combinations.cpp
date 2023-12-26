// 100% CORRECT
// can be calculated with some const formula or as 2^n - extra(where extra is 2^1, 2^2... based on modulo of 6 and factor of 6)
#include<iostream>
using namespace std;

typedef unsigned long long ull;

#define MOD 1000000007ull
ull rez = 1;

int dp[(int)1e6 + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        ull sum = 0;
        for (int j = 0; j < 6 && j <= i; j++) sum += (ull)dp[i - j] % MOD;
        dp[i + 1] = sum % MOD;
    }
    cout << dp[n];
    return 0;
}