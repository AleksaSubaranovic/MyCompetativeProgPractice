#include<iostream>
#include<string.h>
using namespace std;

char a[100], b[100];
int n,m;
int LCS[100+1][100+1];

// DPS tabulation, no recursion need aditional bool for every element of matrix and time is better then regular recursive otherwise
int lcs(){
	// LOOP N*M times
	for(int i = 0; i<=n; i++)
	for(int j = 0; j<=m; j++){
		if (i == 0 || j == 0) LCS[i][j] = 0;
		else if (a[i-1] == b[j-1]) LCS[i][j] = LCS[i-1][j-1] + 1; //if chars are same then add +1
		else LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]); // if not then find max
	}
	return LCS[n][m];
}

main(){
	// INPUT
	ios::sync_with_stdio(false);
	cin >> a >> b;
	n = strlen(a); m = strlen(b);
	cout << lcs();
}
