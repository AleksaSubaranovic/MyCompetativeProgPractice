// 100% CORRECT
// not dynamic programming
#include<iostream>
using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n; ull res = 0;
    while (n)
    {
        int maxi = n % 10;
        int copy = n / 10;
        while (copy)
        {
            if (copy % 10 > maxi) maxi = copy % 10;
            if (maxi == 9) break;
            copy /= 10;
        }
        res++;
        n -= maxi;
    }
    cout << res;
    return 0;
}
