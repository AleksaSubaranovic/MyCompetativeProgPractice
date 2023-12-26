// 100% CORRECT
#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;

struct Project
{
    int begin, end;
    ull reward; 
} arr[200000];

// for sorting array
bool compare(const Project& a, const Project& b)
{
    return a.end < b.end;
}

// for lower bound, comparing Projects with begin time
bool compare2(const Project& a, const int& b)
{
    return a.end < b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].begin >> arr[i].end >> arr[i].reward;
    sort(arr, arr + n, &compare);

    for (int i = 1; i < n; i++)
    {
        int ind = lower_bound(arr, arr + i, arr[i].begin, &compare2) - arr - 1;
        // if ind == -1 all project ends are larger or equal
        if (ind != -1) arr[i].reward += arr[ind].reward;
        if (arr[i].reward < arr[i - 1].reward) arr[i].reward = arr[i - 1].reward;
    }
    cout << arr[n - 1].reward;
    return 0;
}