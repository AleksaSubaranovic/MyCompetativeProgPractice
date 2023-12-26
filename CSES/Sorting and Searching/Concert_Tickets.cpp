// 100% CORRECT
#include<iostream>
#include<set>
using namespace std;

typedef  long long ll;

#define MAX_SIZE (int)2e5

multiset<int> tickets;
multiset<int>::iterator it;

void SOLVE()
{
    ll peeps[MAX_SIZE];
    ll X;
    int n,m;

    cin >> n >> m;
    for (int i = 0; i < n; i++) { cin >> X; tickets.emplace(X); }
    for (int i = 0; i < m; i++) cin >> peeps[i];

    for (int i = 0; i < m; i++)
    {
        if (!tickets.empty())
        {
            it = tickets.upper_bound(peeps[i]);
            if (it == tickets.begin()) cout << "-1\n";
            else
            {
                it--;
                cout << *it << '\n';
                tickets.erase(it);
            }
        }
        else cout << "-1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    SOLVE();

    return 0;
}
