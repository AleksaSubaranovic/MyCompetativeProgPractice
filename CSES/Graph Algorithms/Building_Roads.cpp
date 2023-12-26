// 100% CORRECT
#include<iostream>
#include<list>
using namespace std;

typedef unsigned long long ull;

int n, m;

list<int> adj[100001];
bool visited[100001];
int k;
int newEdges[100001];

void DFS(int v)
{
    visited[v] = true;
    for (auto it = adj[v].begin(); it != adj[v].end(); it++)
        if (!visited[*it]) DFS(*it);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int v, u;
    while (m--)
    {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    DFS(1);
    for (int i = 2; i <= n; i++)
        if (!visited[i])
        {
            newEdges[k++] = i;
            DFS(i);
        }
    cout << k << '\n';
    for (int i = 0; i < k; i++) cout << 1 << ' ' << newEdges[i] << '\n';

    return 0;
}
