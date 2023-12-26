// 100% CORRECT
#include<iostream>
using namespace std;

typedef unsigned long long ull;

bool dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int X;
    dp[0] = true;
    int max = n * 1000;
    while (n--)
    {
        cin >> X;
        for (int i = max; i >= X; i--) dp[i] = dp[i] || dp[i - X];
    }
    int res = 0;
    for (int i = 1; i <= max; i++) if (dp[i]) res++;
    cout << res << '\n';
    for (int i = 1; i <= max; i++) if (dp[i]) cout << i << ' ';
    return 0;
}
