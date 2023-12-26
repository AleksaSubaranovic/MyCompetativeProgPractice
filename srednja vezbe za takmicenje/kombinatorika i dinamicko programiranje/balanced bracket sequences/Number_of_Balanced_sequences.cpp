// fix BinCoef
#include<iostream>
#include<cmath>
using namespace std;

typedef unsigned long long ull;

long long BinCoef(int n, int k)
{
    if (n == 0 || k == 0) return -1;
    if (k > n) return -1; // error case not needed
    long long up = 1;
    for (int i = n; i > k; i++) up *= i;
    long long down = 1;
    for (int i = 2; i <= k; i++) down *= i;
    return up / down;
}

long long GetNumOfBalancedSequences(int length)
{
    if (length & 1) return 0;
    else
    {
        length /= 2; // pair of brackets
        return (long long) (1 / (length + 1) * BinCoef(2 * length, length));
    }
}

long long GetNumOfBalancedSequences(int length, int numOfBracketTypes)
{
    if (length & 1) return 0;
    else
    {
        length /= 2;
        return (long long) (1 / (length + 1) * BinCoef(2 * length, length) * pow(numOfBracketTypes, length));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, k;
    cin >> a >> b >> k;
    cout << GetNumOfBalancedSequences(a);
    cout << endl << GetNumOfBalancedSequences(b, k);
    return 0;
}
