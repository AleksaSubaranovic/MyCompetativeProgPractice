// ranac
#include<stdio.h>

int n, V, v[20], br[20], optBr[20], c[20], maxC = 0; // n je broj predmeta, v[]vrednosti, c[]cene, V je zapremina ranca

void Ubaci(int poz, int prV, int trenC){
	if(poz == n){ // dok se svi predmeti ne ispitaju
		if(trenC > maxC){ // da li je ovo max cena
			for(int i = 0; i<n; i++) optBr[i] = br[i]; // ako jeste upisujemo koliko puta se koristi koji predmet
			maxC = trenC; // nova max cena
		}
	}
	else for(int i=0; i<=prV/v[k]; i++){ // ako je poz nula onda se predmet ne koristi, i ogranicavamo max granicu ranca 
		br[poz] = i; // pamtimo koliko puta se koristi ovaj predmet
		Ubaci(poz+1, prV-br[k]*v[k], trenC+br[k]*c[k]); // rekurzijom ponavljamo
	}
}
// prvi slucaj za 3 predmeta ce biti 000 pa 001, pa 002 ... pa 00max, pa 010.... sve dok ne prodjemo sve slucajeve
// mozemo koristiti jedan predmet nula, jednom ili vise puta
// zato prolazimo kroz sve slucajeve dok ranac nije pun ali nama je bitna max cena pa mozemo da prodjemo kroz sve predmete i ne napunimo ranac ali dobijemo najvecu cenu
main(){
	
	scanf("%d%d", &V, &n);
	for(int i = 0; i<n; i++) scanf("%d%d", &v[i], &c[i]);
	Ubaci(0, V, 0);
	printf("Max cena je %d\n", maxC);
	for(int i = 0; i<n; i++) printf("%d predmet, %d kom\n", i+1, optBr[i]);
	
	
}
