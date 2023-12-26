// 100% CORRECT
#include<iostream>
#include<list>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

typedef unsigned long long ull;
typedef pair<ull, int> parULL; // first = distance used for sorting, second is vertex

#define MAX (ull)1e14 + 1 // 100000 * 1000000000

int n, m;
vector<pair<int, int> > adj[100001]; // MUST USE VECTOR, lists were too slow
ull dist[100001];
priority_queue<parULL, vector<parULL>, greater<parULL> > pq; // min heap
bool visited[100001];


void Dijkstra()
{
    pq.push(make_pair(0ull, 1));
    dist[1] = 0;

    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        visited[v] = true;

        for (auto i : adj[v])
        {
            int u = i.first, c = i.second;

            if (!visited[u] && dist[u] > dist[v] + (ull)c)
            {
                dist[u] = dist[v] + (ull)c;
                pq.push(make_pair(dist[u], u));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, u, c;
    cin >> n >> m;
    while (m--)
    {
        cin >> v >> u >> c;
        adj[v].push_back(make_pair(u, c));
    }
    for (int i = 2; i <= n; i++) dist[i] = MAX;
    Dijkstra();
    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
    return 0;
}
