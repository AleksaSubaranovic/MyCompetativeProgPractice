// 100% CORRECT
#include<iostream>
using namespace std;

typedef unsigned long long ull;

int dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            } // minimal squares of current rectangle is minimal sum of prev. rectangles
            // example:
            // rec 3, 5 => can be sum of recs 1,5 + 2,5 or 3,1 + 3,4 or 3,2 + 3,3
            // add + 1 for last cut
            int maxi = i * j;
            int end = i / 2;
            for (int k = 1; k <= end; k++)
                if (maxi > dp[k][j] + dp[i - k][j]) maxi = dp[k][j] + dp[i - k][j];
            end = j / 2;
            for (int k = 1; k <= end; k++)
                if (maxi > dp[i][k] + dp[i][j - k]) maxi = dp[i][k] + dp[i][j - k];
            dp[i][j] = maxi + 1;
        }
    cout << dp[a][b];
    return 0;
}
