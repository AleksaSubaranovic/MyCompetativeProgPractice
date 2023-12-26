// 100% CORRECT
// can be optimized, there is no need to check every consecutive non zero number
#include<iostream>
using namespace std;

typedef unsigned long long ull;

#define MOD 1000000007ll

int Prev[102], Curr[102];

#define EMPTY_ARRAY(arr, length) for (int ii = 0; ii < length; ii++) arr[ii] = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int *prevPtr = Prev, *currPtr = Curr;
    int n, m, X;
    cin >> n >> m;

    // first element
    cin >> X;
    if (X == 0)
    {
        for (int i = 1; i <= m; i++) prevPtr[i] = 1;
    }
    else prevPtr[X] = 1;

    // rest of array
    while (--n)
    {
        cin >> X;
        if (X == 0)
        {
            for (int i = 1; i <= m; i++) currPtr[i] = ((long long)prevPtr[i - 1] + prevPtr[i] + prevPtr[i + 1]) % MOD;
        }
        else
        {
            EMPTY_ARRAY(currPtr, m + 2)
            currPtr[X] = ((long long)prevPtr[X - 1] + prevPtr[X] + prevPtr[X + 1]) % MOD;
        }
        swap(currPtr, prevPtr); // to remember just latest changes, changes from before are ignored
    }
    long long res = 0;
    for (int i = 1; i <= m; i++) res += ((long long) prevPtr[i]) % MOD;
    cout << res % MOD;
    return 0;
}
