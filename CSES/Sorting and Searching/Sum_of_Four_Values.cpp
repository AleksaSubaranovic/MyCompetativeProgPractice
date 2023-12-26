// 100% CORRECT
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;
pair<int, int> p[1000];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, X;
    cin >> n >> x;
    for (int i = 0 ; i < n; i++)
    {
        cin >> X;
        p[i] = make_pair(X, i);
    }
    sort(p, p + n);
    int i = 0,j = n - 1,k,l;
    while (i != j)
    {
        k = i + 1;
        while (k != j)
        {
            l = k + 1;
            while (l != j)
            {
                long long sum = p[i].first + p[j].first + p[k].first + p[l].first;
                if (sum > x) j--;
                else if (sum < x) l++;
                else {
                    cout << p[i].second + 1 << ' ' << p[k].second + 1 << ' ' << p[l].second + 1 << ' ' << p[j].second + 1;
                    return 0;
                }
            }
            k++; j = n - 1;
        }
        i++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
