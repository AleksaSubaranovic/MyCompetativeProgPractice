#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool moze(string s, string t) {
	vector<int> f(26, 0);
	for (char x : s)
		f[x - 'A']++;
	for (char x : t)
		f[x - 'A']--;
	return count(f.begin(), f.end(), 0) == 25;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, sol = 1;
	string s;

	cin >> n >> s;
	for (int i=2; i<=n; i++) {
		string t;
		cin >> t;
		if (moze(s, t)) {
			sol = i;
			s = t;
		} else {
			break;
		}
	}

	cout << sol << '\n';
}
