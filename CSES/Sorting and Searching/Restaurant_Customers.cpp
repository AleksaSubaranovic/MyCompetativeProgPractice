// 100% CORRECT
#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;
#define MAX_SIZE (int)2e5

int p1[MAX_SIZE], p2[MAX_SIZE];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p1[i] >> p2[i];

    sort(p1, p1 + n, less<int>());
    sort(p2, p2 + n, less<int>());

    ull solution = 0; int i = 0, j = 0;
    ull curr = 0;
    while (i < n && j < n)
    {
        if (p1[i] < p2[j])
        {
            curr++;
            solution = max(curr, solution);
            i++;
        }
        else j++, curr--;

    }

    cout << solution;
    return 0;
}
