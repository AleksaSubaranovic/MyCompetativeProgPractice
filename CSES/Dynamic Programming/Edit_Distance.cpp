// 100% CORRECT
#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;

int dp[5002][5002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int i = 0; i <= m; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
    else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1; // diagonal as well cuz it character can be changed also
    cout << dp[n][m];
    return 0;
}

