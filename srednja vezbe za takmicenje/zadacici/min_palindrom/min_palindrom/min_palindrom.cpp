#include<iostream>
#include<algorithm>
using namespace std;

int matrix[10][10];
int n, m;
int dp[10][10];

bool isPalindrom(int broj) {
	int n = 0, temp[18];
	while (broj > 0) temp[n++] = broj % 10, broj /= 10;
	if (n == 1) return true;
	for (int i = 0, l = n / 2; i < l; i++) if (temp[n - i - 1] != temp[i]) return false;
	return true;
}

void rekIspis(int i, int j) {
	if (i && j != m - 1) if (dp[i - 1][j] < dp[i][j + 1]) rekIspis(i - 1, j);
	else rekIspis(i, j + 1);
	else if (i) rekIspis(i - 1, j);
	else if (j != m - 1) rekIspis(i, j + 1);
	cout << '(' << i << ',' << j << ')';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> matrix[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) matrix[i][j] = isPalindrom(matrix[i][j]);

	dp[0][m - 1] = matrix[0][0];
	for (int i = m - 1; i >= 0; i--) dp[0][i] = dp[0][i + 1] + matrix[0][i];
	for (int i = 1; i < n; i++) dp[i][m - 1] = dp[i - 1][m - 1] + matrix[i][m - 1];
	for (int i = 1; i < n; i++)
		for (int j = m - 1; j >= 0; j--) dp[i][j] = min(dp[i - 1][j], dp[i][j + 1]) + matrix[i][j];


	rekIspis(n - 1, 0);
	return 0;
}