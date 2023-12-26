#include<iostream>
using namespace std;

int N;
bool board[100][100];

// property of diagonals is that sum of i and j for right diagonal is const
// for left it's i-j + N-1

int ld[30]; // left diagonal 2*N-1
int rd[30]; // right diagonal size = N*2-2
int cl[30]; // column

// check if it it's safe to place queen on this row and column
/*bool isSafe(int row, int col){
	for (int i = 0; i < col; i++) if (board[row][i]) return false;
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
	for (int i = row, j = col; i < 0 && j >= N; i++, j--) if (board[i][j]) return false;
	return true;
}*/



bool SolveNQueen(int col){
	if (col == N) return true;
	
	for (int i = 0; i < N; i++) if (ld[i-col + N -1] != 1 && rd[i+col] != 1 && cl[i] != 1){
		board[i][col] = true;
		ld[i-col+N-1] = rd[i+col] = cl[i] = 1;
		if (SolveNQueen(col+1)) return true;
		board[i][col] = false;
		ld[i-col+N-1] = rd[i+col] = cl[i] = 0;		
	}
	return false;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) board[i][j] = false;
	
	if (SolveNQueen(0)) for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << board[i][j] << ' ';
		cout << endl;
	}
}
