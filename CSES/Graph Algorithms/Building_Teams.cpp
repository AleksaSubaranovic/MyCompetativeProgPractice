// 100% CORRECT
#include<iostream>
#include<list>
using namespace std;

typedef unsigned long long ull;
int n;
list<int> adj[100001];
short int group[100001];

bool impossible;

void DFS(int v)
{
    int opp = group[v] == 1 ? 2 : 1;
    for (auto it = adj[v].begin(); it != adj[v].end() && !impossible; it++)
        if (group[*it] == 0)
        {
            group[*it] = opp;
            DFS(*it);
        }
        else if (group[*it] != opp)
        {
            cout << "IMPOSSIBLE";
            impossible = true;
            return;    
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, v, u;
    cin >> n >> m;
    while (m--)
    {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (impossible) break;
        if (group[i] == 0)
        {
            group[i] = 1;
            DFS(i);
        } 
    }
    if (!impossible) for (int i = 1; i <= n; i++) cout << group[i] << ' ';
    return 0;
}
