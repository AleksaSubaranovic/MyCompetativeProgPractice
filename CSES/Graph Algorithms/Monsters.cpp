// 100% CORRECT
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

typedef unsigned long long ull;

int n, m;
pair<short, short> start;
char matrix[1000][1000];
int monsters[1000][1000];

pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char movements[] = "RLDU";
bool visited[1000][1000];
short path[1000001];

bool DFS(int row, int col, int length)
{
    if (row == 0 || row == n - 1 || col == 0 || col == m - 1)
    {
        cout << "YES\n";
        cout << length << '\n';
        for (int i = 1; i <= length; i++) cout << movements[path[i]];
        return true;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int currRow = row + dir[i].first, currCol = col + dir[i].second;
            if (matrix[currRow][currCol] == '.'
            && !visited[currRow][currCol]
            && (length + 1 < monsters[currRow][currCol] || monsters[currRow][currCol] == 0))
            {
                path[length + 1] = i;
                if (DFS(currRow, currCol, length + 1)) return true;
            }
        }
    }
    return false;
}

queue<pair<pair<short, short>, int>> q;
void BFS()
{
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        short row = p.first.first, col = p.first.second;
        for (int i = 0; i < 4; i++)
        {
            int currRow = row + dir[i].first, currCol = col + dir[i].second;
            if (currRow < 0 || currRow >= n || currCol < 0 || currCol >= m) continue;
            if (!monsters[currRow][currCol] && matrix[currRow][currCol] != '#')
            {
                q.push(make_pair(make_pair(currRow, currCol), p.second + 1));
                monsters[currRow][currCol] = p.second + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A') start = {i, j};
            else if (matrix[i][j] == 'M')
            {
                q.push(make_pair(make_pair(i, j), 0));
                monsters[i][j] = 1;
            }
        }
    // Monsters will be set with BFS, path will be found with DFS
    BFS();
    if (!DFS(start.first, start.second, 0)) cout << "NO";
    return 0;
}
