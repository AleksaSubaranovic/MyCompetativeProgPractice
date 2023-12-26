// 100% CORRECT
// modified solution from NQueens Problem
#include<iostream>
using namespace std;

typedef unsigned long long ull;

char map[8][8];
ull solution = 0;
int ld[30];
int rd[30];
int cl[30];
bool board[30][30];

bool Solve(int col)
{
    if (col == 8) {return true;}
    for (int i = 0; i < 8; i++ )
        if (ld[i-col + 7] != 1 && rd[i+col] != 1 && cl[i] != 1 && map[i][col] != '*')
        {
            board[i][col] = true;
            ld[i-col+7] = rd[i+col] = cl[i] = 1;
            if (Solve(col + 1)) solution++; // modified
            board[i][col] = false;
            ld[i-col+7] = rd[i+col] = cl[i] = 0;
        }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) cin >> map[i][j];

    Solve(0);

    cout << solution;
    return 0;
}
