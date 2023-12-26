// 100% CORRECT
#include<iostream>
#include<queue>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<ll> rooms;
    priority_queue<ll> peeps;
    ll n,m,k, X;
    cin >> n >> m >> k;
    
    int solution = 0;
    for (int i = 0; i < n; i++) { cin >> X; peeps.emplace(X);}
    for (int i = 0; i < m; i++) { cin >> X; rooms.emplace(X);}

    while (!rooms.empty() && !peeps.empty())
    {
        if (abs(rooms.top() - peeps.top()) <= k)
        {
            solution++;
            rooms.pop();
            peeps.pop();
        }
        else if (rooms.top() > peeps.top()) rooms.pop();
        else peeps.pop();
    }
    cout << solution;

    return 0;
}
