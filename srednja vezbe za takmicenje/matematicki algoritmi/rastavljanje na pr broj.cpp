// rastavljanje na proste brojeve i stepene
#include<iostream>
using namespace std;

int p[30], a[30]; // p = delilac, a = broj tog delioca;
int X;
int n,br,d;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> X;
	while (X--){
		br = 0, d = 2;
		cin >> n;
		while(n>1){ // while broj n veci od 1
			if(n%d == 0){ // ako je deljiv sa deliocem
				p[br] = d; // definisemo vrednost prvog delioca
				a[br] = 0; // definisemo pocetni broj delilaca
				while(n%d == 0){ // dok je deljiv
					a[br]++; // povecavamo broj delilaca
					n = n/d; // delimo broj
				}
				br++; // povecavamo brojac 
			}
			d++; // povecavamo delilac
		}
		for(int i=0; i<br-1; i++)cout << p[i] << "^" << a[i] << '*';
		cout << p[br-1] << '^' << a[br-1] << '\n';
	}
}
