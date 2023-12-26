#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int niz[20], n;
int tail[20], tail_length;


int LIS_SIZE_ONLY(){
	tail[0] = niz[0];
	tail_length++;
	for (int i = 1; i < n; i++)
		// nova najmanja vrednost
		if (niz[i] < tail[0]) tail[0] = niz[i];
		
		// ako je trenutni broj veci od predhodnog
		else if (niz[i] > tail[tail_length - 1]) tail[tail_length++] = niz[i];
		
		
		// ako je trenutni broj manji od zadnjeg najveceg
		// potencijalni clan LIS
		else {
			tail[lower_bound(tail, tail + tail_length, niz[i]) - tail] = niz[i];
		}
		
		cout << tail_length;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> niz[i];

	return 0;
}
