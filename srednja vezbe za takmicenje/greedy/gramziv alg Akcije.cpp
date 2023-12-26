// gramziv algoritam
#include<stdio.h>
#include<algorithm> // #include<bitsstd.h> usporavaaaaaaaa ali ima sveeeeeee
using namespace std;

struct Aktivnost{
	int start, finish;
};

bool RanijeZavrsena(Aktivnost a, Aktivnost b){ // da bi ih sortovali po vremenu zavrsetka akcije pa kasnije proverili da li je moguce obaviti akciju
	if(a.finish <= b.finish) return true; 
	else return false;
}

Aktivnost a[1000]; int n;

main(){
	scanf("%d", &n);
	for(int i = 0; i<n; i++) scanf("%d %d", &a[i].start, &a[i].finish);
	sort(a, a+n, RanijeZavrsena);
	int j = 0, rez = 1; // rez = 1 jer uvek mozemo izvrsiti jednu akciju
	for(int i =1; i<n; i++) // uporedjujemo od druge akcije sa prethodnom
	if(a[i].start>=a[j].finish){ // da li je pocetak druge veci od kraja prve tj da li je moguce izvrsiti obe akcije
		rez++; // ako jeste povecavamo brojac akcija
		j = i; // menjamo akciju za uporedjivanje da bi mogli da uporedimo sa sledecom akcijom 
	}
	printf("%d", rez);
	
}
