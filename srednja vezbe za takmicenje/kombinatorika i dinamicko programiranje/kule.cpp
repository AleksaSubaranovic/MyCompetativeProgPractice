#include<iostream>
using namespace std;

int n;

void Print(char start, char end, int number, char help) {
	if (number) {
		Print(start, end, number - 1, help);
		cout << start << ' ' << end << ' ' << number << '\n';
		Print(help, end, number - 1, start);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cout << n << ' ' << ((unsigned long long)1 << n) - 1 << "\n";

	Print('A', 'C', n, 'B');
	return 0;
}
