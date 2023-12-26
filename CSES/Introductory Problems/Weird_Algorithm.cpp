// 100% CORRECT
#include<iostream>
using namespace std;

#define ll long long

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    unsigned ll n; bool odd;
    cin >> n;
    odd = n & 1;
    while (n != 1)
    {
        cout << n << ' ';
        if (odd) {n = n * 3 + 1; odd = false;}
        else {n /= 2; odd = n & 1;}
    }

    cout << 1;

    return 0;
}

