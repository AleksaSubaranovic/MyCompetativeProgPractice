// 100% CORRECT
// can be optimized, no need for DFS but good enough
#include<iostream>
#include<utility>
using namespace std;

typedef unsigned long long ull;
#define WALL '#'
#define FLOOR '.'

char matrix[1000][1000];
bool visited[1000][1000];

int n, m;

void DFS(int i, int j)
{
    if (visited[i][j]) return;
    else
    {
        visited[i][j] = true;
        
        // check for right
        if (j + 1 < m) if (matrix[i][j + 1] == FLOOR) DFS(i, j + 1);
        
        // check for left
        if (j > 0) if (matrix[i][j - 1] == FLOOR) DFS(i, j - 1);

        // check for top
        if (i > 0) if (matrix[i - 1][j] == FLOOR) DFS(i - 1, j);

        // check for bot
        if (i + 1 < n) if (matrix[i + 1][j] == FLOOR) DFS(i + 1, j);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int sol = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> matrix[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == FLOOR && !visited[i][j])
            {
                sol++;
                DFS(i, j);
            }
    cout << sol;

    return 0;
}