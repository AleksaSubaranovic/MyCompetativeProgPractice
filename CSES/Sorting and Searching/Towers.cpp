// 100% CORRECT
#include<iostream>
#include<set>
using namespace std;

typedef unsigned long long ull;
multiset<int> m;
multiset<int>::iterator it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; int X;
    cin >> n;
    // first
    cin >> X;
    m.emplace(X);
    int solution = 1;
    for (int i = 1; i < n; i++)
    {
        cin >> X;
        it = m.upper_bound(X);
        if (it == m.end())
        {
            solution++;
            m.emplace(X);
        }
        else
        {
            m.erase(it);
            if (X != 1) m.emplace(X);
        }
    }

    cout << solution;

    return 0;
}
