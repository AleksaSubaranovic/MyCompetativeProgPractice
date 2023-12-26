// 100% CORRECT
#include<iostream>
#include<map>
using namespace std;

typedef unsigned long long ull;

multimap<int, int> mp;

#define EXIT cout << "IMPOSSIBLE"; return 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, sum;
    cin >> n >> sum;
    pair<int, int>p;
    for (int i = 0; i < n; i++)
    { 
        cin>>p.first;
        p.second = i + 1;
        mp.emplace(p);
    }

    map<int, int>::iterator it1, it2, temp;
    it1 = mp.begin(); it2 = mp.end(); it2--;
    
    if (mp.size() == 1) {EXIT}
    else
    while (!mp.empty())
    {
        if ((it1->first) + (it2->first) ==  sum)
        {
            if (it1->second == it2->second) {EXIT}
            cout << it1->second << ' ' << it2->second;
            return 0;
        }
        else if ((it1->first) + (it2->first) > sum)
        {
            temp = it2;
            it2--;
            mp.erase(temp);
        }
        else
        {
            temp = it1;
            it1++;
            mp.erase(temp);
        }
        
    }
    EXIT
}
