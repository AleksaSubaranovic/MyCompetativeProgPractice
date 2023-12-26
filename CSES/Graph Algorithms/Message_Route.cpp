// 100% CORRECT
#include<iostream>
#include<list>
#include<queue>
using namespace std;

typedef unsigned long long ull;

list<int> adj[100001];
bool visited[100001];
int path[100001];
int n;

void PRINT(int v, int length)
{
    if (v == -1) cout << length << '\n';
    else
    {
        PRINT(path[v], length + 1);
        cout << v << ' ';
    }
}

void BFS()
{
    queue<int> q;
    q.push(1);
    path[1] = -1;
    visited[1] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (v == n)
        {
            PRINT(n, 0);
            return;
        } 
        for (auto it = adj[v].begin(); it != adj[v].end(); it++)
            if (!visited[*it]) path[*it] = v, visited[*it] = true, q.push(*it);
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    int v, u;
    cin >> n >> m;
    while (m--)
    {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    BFS();
    return 0;
}
