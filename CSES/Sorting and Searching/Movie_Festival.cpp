// 100% CORRECT
#include<iostream>
#include<algorithm>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;
#define MAX_SIZE (int)2e5

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

pair<int, int> p[MAX_SIZE];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p, p + n, &compare);
    int end = p[0].second;
    int solution = 1;
    for (int i = 1; i < n; i++)
    {
        if (p[i].first >= end) solution++, end = p[i].second;
    }
    cout << solution;
    return 0;
}
