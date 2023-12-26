// 100% CORRECT
// can be speeded up, with 2^63 maybe, and right shift
#include<iostream>
using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const ull yeetNumber = 1073741824ull;
    const ull notYeetNumber = (ull)(1e9 + 7);
    const ull yeet = yeetNumber % notYeetNumber;
    int n;
    cin >> n;
    ull leftover = 1;
    ull x;
    while (n)
    {
        if (n >= 30)
        {
            leftover *= yeet;
            leftover %= notYeetNumber;
            n-=30;

        }
        else {
            x = 1 << n;
            x = (x % notYeetNumber * leftover) % notYeetNumber;
            n = 0;
        }
    }
    cout << x;

    return 0;
}
