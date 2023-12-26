// 100% CORRECT
// solution is that sum of both piles must be dividable by 3, and max(a, b) <= 2 * min(a, b)
// logic goes from examples where from largest pile we take 2 coins and 1 coin from smallest
// if smallest pile is a, then b is largest, when b = 2a, we can divide piles correctly
// we can remove coins as long as we have equall piles of 3k,
// if a = 2b is correct we can say a + b = 3b, so factor is 3
// but we need a <= 2 * b

#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;

#define YES cout << "YES\n";
#define NO cout << "NO\n";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    ull a,b;
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        
        if (a == 0 && b == 0) YES
        else if( a == 0 || b == 0) NO
        else if ((ull)(a + b) % 3ull == 0ull && (max(a, b) <= 2ull * min(a, b))) YES
        else NO
    }

    return 0;
}
