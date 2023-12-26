#include<iostream>
using namespace std;

// a i b su brojevi svih vrsta i kolona koje su popunjene
// (a+b)*N je zbir svih popunjenih polja gde su neka polja dva put popunjena
// za svako a postoji zauzeto jedno polje na svakoj koloni i obrnuto
// pa je formula (a+b)*N - a*b, gde je a*b broj svih polja koja su dva put zauzeta

long long a, b;
int N, M;
bool V[1000001], K[1000001];
int x, y;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> N >> M;
	while (M--){
		cin >> x >> y;
		if (!V[x]) V[x] = true, a++;
		if (!K[y]) K[y] = true, b++;
	}
	
	cout << N*(a+b)-a*b;
	return 0;
}
