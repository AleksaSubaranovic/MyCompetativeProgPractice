// 100% CORRECT
// use literal ull insted of casting
#include<iostream>
using namespace std;


typedef unsigned long long ull;

ull temp;

const ull extraConst = 2 + 2 + 3 + 3;
const ull extraConst2 = 1 + 1 + 1 + 1;

#define SUM_OF_ALL(num) (ull)((ull)(num) * (ull)((num) - 1) / (ull)2)

ull GetFreeSlots(const int& i)
{
    temp = (ull)((i - 4) * 4) + extraConst;
    temp *= (ull)(i - 2);
    return SUM_OF_ALL(i * i) - (ull)(temp + extraConst2 + (ull)((i - 4) * 2));
}

ull GetConsts(const int& i)
{
    switch (i)
    {
        case 1 : return 0;
        case 2 : return 6;
        case 3 : return 28;
        case 4 : return 96;
        case 5 : return 252;
        case 6 : return 550;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i < 7 && i <= n; i++) cout << GetConsts(i) << '\n';

    for (int i = 7; i <= n; i++) cout << GetFreeSlots(i) << '\n';

    return 0;
}
