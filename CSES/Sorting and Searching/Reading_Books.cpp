// 100% CORRECT
#include<iostream>
using namespace std;

typedef unsigned long long ull;
ull arr[(int)2e5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    ull maxi = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > maxi) maxi = arr[i];

    ull sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    sum -= maxi;
    
    if (maxi > sum) cout << maxi*2ull;
    else cout << sum + maxi;

    return 0;
}
