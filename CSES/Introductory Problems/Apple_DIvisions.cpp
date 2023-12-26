// 100% CORRECT
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ull;

ull array[21];
int n;
ull minDif = (ull)1e9;

void combs(int index, ull sum1, ull sum2)
{
    if (index == n)
    {
        if (abs(sum1 - sum2) < minDif) minDif = abs(sum1 - sum2);
    }
    else
    {
        sum1 += array[index];
        combs(index + 1, sum1, sum2);
        sum1 -= array[index];
        sum2 += array[index];
        combs(index + 1, sum1, sum2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> array[i];
    combs(0, 0ull, 0ull);
    cout << minDif;

    return 0;
}
