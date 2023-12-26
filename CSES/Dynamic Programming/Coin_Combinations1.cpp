// 100% CORRECT
#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;

int dp[1000000 + 1];
int arr[1000000];

#define FILL_ARRAY(arr, length, value) for (int ii = 0; ii < length; ii++) arr[ii] = (value);
#define MOD 1000000007


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) cin >> arr[i];

    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        ull sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i >= arr[j])
            {
                sum += (ull)dp[i - arr[j]];
            }
        }
        dp[i] = sum % MOD;
    }
    cout << dp[x];
    return 0;
}
