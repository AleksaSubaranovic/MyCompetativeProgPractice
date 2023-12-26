// 100% CORRECT
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

typedef unsigned long long ull;

int n, m;
pair<short, short> start, finish;
char matrix[1000][1000];

pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char movements[] = "RLDU";
bool visited[1000][1000];
short path[1000][1000];

void PRINT(int row, int col, int length)
{
    if (path[row][col] == -1)
    {
        cout << length << '\n';
    }
    else
    {
        PRINT(row - dir[path[row][col]].first, col - dir[path[row][col]].second, length + 1);
        cout << movements[path[row][col]];
    }
}

bool BFS()
{
    queue<pair<int, int> > q;
    visited[start.first][start.second] = true;
    path[start.first][start.second] = -1;
    q.push(start);
    while(!q.empty())
    {
        int row = q.front().first, col = q.front().second;
        q.pop();
        
        if (row == finish.first && col == finish.second)
        {
            cout << "YES\n";
            PRINT(row, col, 0);
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int currRow = row + dir[i].first, currCol = col + dir[i].second;
            if (currRow < 0 || currCol < 0 || currRow >= n || currCol >= m) continue;
            if (matrix[currRow][currCol] == '.' && !visited[currRow][currCol])
            {
                visited[currRow][currCol] = true;
                path[currRow][currCol] = i;
                q.push(make_pair(currRow, currCol));
            }
        }
    }
    return false;
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
            else if (matrix[i][j] == 'B') finish = {i, j}, matrix[i][j] = '.';
        }
    if (!BFS()) cout << "NO";


    return 0;
}
