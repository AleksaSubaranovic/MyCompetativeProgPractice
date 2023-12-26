// 100% CORRECT
#include<iostream>
using namespace std;

typedef unsigned long long ull;

char matrix[1001][1001];
unsigned long long dp[1001][1001];

#define SAFE '.'
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> matrix[i][j];
    if (matrix[0][0] == SAFE)
    {
        dp[0][0] = 1;
        for (int i = 1; i < n; i++) if (matrix[0][i] == SAFE) dp[0][i] = 1; else break;
        for (int i = 1; i < n; i++) if (matrix[i][0] == SAFE) dp[i][0] = 1; else break;

        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == SAFE) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        cout << dp[n - 1][n - 1];
    }
    else cout << 0;

    return 0;
}
