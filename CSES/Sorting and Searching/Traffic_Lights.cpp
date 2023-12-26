// 100% CORRECT
#include<iostream>
#include<set>
#include<map>
using namespace std;

typedef unsigned long long ull;

map<int, int> mp;
multiset<int> lengths;
map<int, int>::iterator itmp;
multiset<int>::iterator it;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, N;
    cin >> N >> n;
    int X;
    pair<int, int> p;
    
    p.first = 0, p.second = N;
    mp.emplace(p);
    lengths.emplace(p.second - p.first);

    for (int i = 0; i < n; i++)
    {
        cin >> X;
        itmp = mp.upper_bound(X);
        itmp--;

        lengths.erase(lengths.lower_bound(itmp->second - itmp->first));

        p = *itmp;
        mp.erase(itmp);
        mp.emplace(make_pair(p.first, X)); lengths.emplace(X - p.first);
        mp.emplace(make_pair(X, p.second)); lengths.emplace(p.second - X);

        it = lengths.end(); it--;
        cout << *it << ' ';
    }


    return 0;
}
