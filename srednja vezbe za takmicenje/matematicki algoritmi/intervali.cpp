#include<iostream>
#include<algorithm>
using namespace std;

int P[100], K[100]; // P je niz pocetka intervala, K je niz kraja intervala
int n, m; // duzina nizova i granicna vrednost intervala(nepotrebna)
int location, max_overlaps, overlaps; // lokacija tacke gde se nalazi najvise intervala, max dostignut broj intervala i broj intervala u trenutku
main(){
	// UPIS
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i<n; i++) cin >> P[i] >> K[i];
	
	// SORTIRANJE
	sort(P,P+n);
	sort(K,K+n);
	
	int i = 1; // brojac za niz P
	int j = 0; // brojac za niz K
	max_overlaps = 1; 
	overlaps = 1;
	location = P[0];
	
	// PETLJA
	while (i<n && j<n){
		if (P[i] <= K[j]){ // 				ako je pocetak manji od kraja onda se ulazi u intreval
			overlaps++; // 					povecava se brojac trenutnih intervala
			if(overlaps > max_overlaps){ // proverava se maksimum intervala na istoj lokaciji
				max_overlaps = overlaps;
				location = P[i];
			}
			i++;
		}
		else{
			overlaps--; // izlazimo iz jednog intervala i zato se smanjuje broj trenutnih intervala
			j++;
		}
	}
	// lokacija se nalazi u najvise intervala
	cout << location;
}
