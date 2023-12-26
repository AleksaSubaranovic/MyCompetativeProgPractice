// 100% CORRECT
#include<iostream>
#include<list>
using namespace std;

typedef unsigned long long ull;

list<int> adj[100001];
bool visited[100001];
int n;
int path[100001];

void PRINT(int v, int start)
{
    if (v == start)
    {
        cout << start << ' ';
    }
    else
    {
        PRINT(path[v], start);
        cout << v << ' ';
    }
}

bool DFS(int v)
{
    for (auto it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if (visited[*it])
        {
            if (*it != path[v]) // if there is cycle, check length of cycle
            {
                int length = 0, u = v;
                while (u != *it) u = path[u], length++;
                if (length >= 2)
                {
                    cout << length + 2 << '\n';
                    PRINT(v, *it);
                    cout << *it;
                    return true;
                }
            }
        }
        else
        {
            path[*it] = v;
            visited[*it] = true;
            if (DFS(*it)) return true;
        }
    }
    return false;
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool finish = false;
    for (int i = 1; i <= n; i++) if (!visited[i])
    {
        visited[i] = true;
        if (DFS(i))
        {
            finish = true;
            break;
        }
    }
    if (!finish) cout << "IMPOSSIBLE";
    return 0;
}
