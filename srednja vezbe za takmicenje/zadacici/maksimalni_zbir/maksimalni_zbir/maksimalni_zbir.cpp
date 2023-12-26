#include<iostream>
#include<algorithm>
using namespace std;

int matrix[10][10];
int n;
int dp[10][10];

void rekIspis(int i, int j) {
	if (i && j != n - 1)
		if (dp[i - 1][j] > dp[i][j + 1]) rekIspis(i - 1, j);
		else rekIspis(i, j + 1);
	else
		if (i) rekIspis(i - 1, j);
		else if (j != n - 1) rekIspis(i, j + 1);
	cout << '(' << i << ',' << j << ')';	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> matrix[i][j];
	dp[0][n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) dp[0][i] = dp[0][i + 1] + matrix[0][i];
	for (int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + matrix[i][0];
	for (int i = 1; i < n; i++)
		for (int j = n - 2; j >= 0; j--) dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
	int maxi = 0;
	for (int i = 0; i < n; i++) if (dp[maxi][maxi] < dp[i][i]) maxi = i;
	rekIspis(maxi, maxi);
	return 0;
}