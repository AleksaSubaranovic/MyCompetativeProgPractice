// 100% CORRECT
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<ll> dq;
    ll n, X, x;
    ll solution = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) { cin >> X; dq.emplace_front(X); }
    sort(dq.begin(), dq.end(), less<ll>());
    while (dq.size() > 1)
    {
        if (dq.front() + dq.back() <= x) 
        {
            solution++;
            dq.pop_back();
            dq.pop_front(); 
        }
        else 
        {
            dq.pop_back();
            solution++;
        }
    }
    if (dq.size() == 1) solution++;
    cout << solution;

    return 0;
}
