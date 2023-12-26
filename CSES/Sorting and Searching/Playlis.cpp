// 100% CORRECT
#include<iostream>
#include<unordered_map>
using namespace std;

typedef unsigned long long ull;

#define MAX_SIZE (int)2e5

int Max, curr, start; // Max is solution, curr is current length, start is index where curr begins (can be removed and optimized)
unordered_map<int, int> mp; // first int is value of number(used for fast comparing), second int is index in array
unordered_map<int, int>::iterator it;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, X;
    pair<int, int> p;
    cin >> n;
    mp.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X;
        it = mp.find(X);
        if (it == mp.end()) // add new element to map
        {
            curr++;
            if (curr > Max) Max = curr;
            p.first = X; p.second = i;
            mp.emplace(p);
        }
        else
        {
            if (it->second < start) // update outdated element's index, and increment curr
            {
                it->second = i;
                curr++;
                if (Max < curr) Max = curr;
            }
            else // update length of curr and change element's index
            {
                curr = i - it->second;
                start = it->second + 1;
                it->second = i;
            }
        }
    }

    cout << Max;
    return 0;
}
