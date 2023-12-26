#include<iostream>
using namespace std;

int *N, *M;
int n,m;
int** dp; 
// gej
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	cin >> n >> m;;
	
	N = new int [n];
	M = new int [m];
	dp = new int* [n+1];
	for (int i = 0; i <= n; i++) dp[i] = new int[m+1];
	
	for (int i = 0; i < n; i++) cin >> N[i];
	for (int i = 0; i < m; i++) cin >> M[i];
	
	for (int i = 0; i <= m; i++) dp[0][i] = 0;
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j<= m; j++)
			if (N[i-1] == M[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			
	cout << n - dp[n][m] + m - dp[n][m];
}

