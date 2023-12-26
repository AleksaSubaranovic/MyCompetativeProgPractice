//16of19
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

#define IMPOSSIBLE {cout<<"IMPOSSIBLE";return 0;}
#define CORRECT {cout<< it1->second + 1 << ' ' << it2->second + 1 << ' ' << temp->second + 1; return 0;}
typedef unsigned long long ull;

multimap<ull, int> mp;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ull n, x; ull X;

    cin >> n >> x;
    for (ull i = 0; i < n; i++) { cin >> X; if (X < x) mp.emplace(make_pair(X, i)); }
    bool b = false;
    multimap<ull, int>::iterator it1, it2, temp; int rez1,rez2,rez3;
    if (n > 2)
    {
        it1 = mp.begin();
        it2 = mp.end(); it2--;
        while (it1 != it2)
        {
            ull sum = ull(it1->first + it2->first);
            if (sum >= x)
            {
                if (it2 != mp.begin()) it2--;
            }
            else
            {
                auto p = mp.equal_range(ull(x - sum));
                for (temp = p.first; temp != p.second; temp++)
                    if(temp->second != it1->second && temp->second != it2->second)
                    {
                        rez1 = it1->second;
                        rez2 = it2->second;
                        rez3 = temp->second; b = true;
                    }
                it1++;
            }
        }
        if (b) cout << rez1 + 1 << ' ' << rez2 + 1 << ' ' << rez3 + 1;
        else IMPOSSIBLE
    }
    else IMPOSSIBLE
}
