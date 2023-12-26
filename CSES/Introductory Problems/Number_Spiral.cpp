// 100% CORRECT
#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long
unsigned ll T;

unsigned ll GetDiag(unsigned ll x)
{
    return x*x - x + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    unsigned ll x, y, z;
    while (T--)
    {
        cin >> x >> y;
        //if (x == y) cout << GetDiag(x) << '\n';
        if (x > y)
        {
            z = GetDiag(x);
            if (x & 1) cout << z - x + y << '\n';
            else cout << z + x - y << '\n';
        }
        else
        {
            z = GetDiag(y);
            if (y & 1) cout << z + y - x << '\n';
            else cout << z - y + x << '\n';
        }
    }

    return 0;
}
