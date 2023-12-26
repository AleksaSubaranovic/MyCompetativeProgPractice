// LIS, Longest Increasing Subsequence
#include<iostream>
#include<algorithm>
using namespace std;

int arr[20], n;
int tail_ind[20];
int prev_ind[20];

// za lower_bound
bool compare(int ind, int value) {
	return arr[ind] < value;
}

void rekIspis(int i) {
	if (i >= 0) rekIspis(prev_ind[i]), cout << arr[i] << ' ';
}

int LIS() {
	for (int i = 0; i < n; i++) prev_ind[i] = -1;
	tail_ind[0] = 0;
	int len = 1;
	for (int i = 1; i < n; i++)
		// menja se pocetak LIS-a da bi se omogucio veci LIS kasnije
		if (arr[i] < arr[tail_ind[0]]) tail_ind[0] = i;

		// LIS se povecava za jedan broj
		else if (arr[i] > arr[tail_ind[len - 1]]) {
			prev_ind[i] = tail_ind[len - 1];
			tail_ind[len++] = i;
		}

		// za broj koji moze biti deo LIS-a 
		// trenutni broj ce zameniti neki prethodni broj koji je veci ili isti da bi omogucuio veci LIS kasnije
		else {
			int pos = lower_bound(tail_ind, tail_ind + len, arr[i], compare) - tail_ind;
			prev_ind[i] = tail_ind[pos - 1];
			tail_ind[pos] = i;
		}

	rekIspis(tail_ind[len - 1]);
	cout << endl;
	return len;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << "DUZINA NAJDUZEG RASTUCEG PODNIZA JE " << LIS();

	return 0;
}