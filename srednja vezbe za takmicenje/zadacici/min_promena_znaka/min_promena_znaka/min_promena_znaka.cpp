#include<iostream>
using namespace std;

int matrix[10][10];
int n;
int dp[10][10];

void rekIspis(int i, int j) {
	if (i && j) if (dp[i - 1][j] < dp[i][j - 1]) rekIspis(i - 1, j);
	else rekIspis(i, j - 1);
	else if (i) rekIspis(i - 1, j);
	else if (j) rekIspis(i, j - 1);
	cout << '(' << i << ',' << j << ')';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> matrix[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) matrix[i][j] = matrix[i][j] > 0 ? 1 : 0;

	dp[0][0] = 0;
	for (int i = 1; i < n; i++) if (matrix[0][i - 1] == matrix[0][i]) dp[0][i] = dp[0][i - 1];
	else dp[0][i] = dp[0][i - 1] + 1;

	for (int i = 1; i < n; i++) if (matrix[i - 1][0] == matrix[i][0]) dp[i][0] = dp[i - 1][0];
	else dp[i][0] = dp[i - 1][0] + 1;

	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			if (dp[i - 1][j] < dp[i][j - 1])
				if (matrix[i - 1][j] == matrix[i][j]) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = dp[i - 1][j] + 1;
			else if (dp[i - 1][j] > dp[i][j - 1])
				if (matrix[i][j - 1] == matrix[i][j]) dp[i][j] = dp[i][j - 1];
				else dp[i][j] = dp[i][j - 1] + 1;
			else if (matrix[i][j - 1] == matrix[i][j]) dp[i][j] = dp[i][j - 1];
			else if (matrix[i - 1][j] == matrix[i][j]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] + 1;
	
	int M = 0;
	for (int i = 0; i < n; i++) if (dp[M][n - 1 - M] > dp[i][n - 1 - i]) M = i;

	rekIspis(M, n - 1 - M); 
	//for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) cout << dp[i][j] << ' '; cout << endl; }

	return 0;
}