// 100% CORRECT
#include<iostream>
using namespace std;

typedef unsigned long long ull;

int arr[(int)2e5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int maxi = arr[0];
    for (int i = 1; i < n; i++) if (maxi < arr[i]) maxi = arr[i];

    long long l = maxi, r = maxi * n; // "smart" guessing with binary search
    while (l < r)
    {
        long long m = (l + r)/2; // no index, so this works
        long long count = 1, sum = 0;
        for (int i = 0 ; i < n; i++)
        {
            sum += arr[i];
            if (sum > m) count++, sum = arr[i];
        }
        if (count > k) l = m + 1ll;
        else r = m;
    }
    cout << l;
    return 0;
}
