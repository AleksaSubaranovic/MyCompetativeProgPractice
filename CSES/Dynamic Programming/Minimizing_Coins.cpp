// 100% CORRECT
#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;

int dp[(int)1e6 + 10];

#define FILL_ARRAY(arr, lenght, value) for (int ii = 0; ii < (lenght); ii++) arr[ii] = (value); 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    FILL_ARRAY(dp, x + 1, INT32_MAX - 1)
    dp[0] = 0; 
    while (n--)
    {
        int a;
        cin >> a;
        for (int i = a; i <= x; i++)
            dp[i] = min(dp[i], dp[i - a] + 1);
        // dp[i] is current smallest number of coins needed for this value
        // dp[i - a] is current smallest number of coins needed for this value - current coinm current coin is used once so +1 to solution
    }
    if (dp[x] != INT32_MAX - 1) cout << dp[x];
    else cout << "-1";
    return 0;
}
