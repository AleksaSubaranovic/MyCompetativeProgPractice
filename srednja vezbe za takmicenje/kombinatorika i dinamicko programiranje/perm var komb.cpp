// perm, var i komb
#include<stdio.h>

double a[100], perm[100];
bool pkoriscen[100];
double var[100];
bool vkoriscen[100];
double komb[100];
int n, k;

void Perm(int poz){ // Pn = !n, _Pn = n!/k1!*k2!...kn!     n=k 
	if(poz==n){ // ako je napravljena jedna permutacija
		for(int i=0;i<n;i++)
		printf("%lf ", perm[i]);
		printf("\n");
	}
	else for(int i=0;i<n;i++) if(!pkoriscen[i]){ // izbrisati bool za sa ponavljanjem
		perm[poz]=a[i]; // dodela vrednosti
		pkoriscen[i]=true; // taj clan se ne ponavlja
		Perm(poz+1); // rekurzija
		pkoriscen[i]=false; // moze se opet koristiti ovaj clan
	} 
}

void Var(int poz){ // V = n*(n-1)*(n-2)*...(n-k+1), _V = n^k
	if(poz==k){ // ako je napravljena jedna variacija
		for(int i=0;i<k;i++)
		printf("%lf ", var[i]);
		printf("\n");
	}
	else for(int i=0;i<n;i++) if(!vkoriscen[i]){ // izbrisati bool za sa ponavljanjem
		var[poz]=a[i]; // dodela vrednosti
		vkoriscen[i]=true; // taj clan se ne ponavlja
		Var(poz+1); // rekurzija
		vkoriscen[i]=false; // moze se opet koristiti ovaj clan
	} 
}

// ind_n prestavlja indeks u originalnom nizu brojeva, ind_k prestavlja indeks u zavrsnom nizu trenutne kombinacije
void Komb(int ind_n, int ind_k){ // C = n!/k!*(n-k)!, _C = (n+k+1)!/k!*(n-1)!  >>C = n*(n-1)/2 
	if(ind_k==k){ // ako je napravljena jedna kombinacija
		for(int i=0;i<k;i++)
		printf("%lf ", komb[i]);
		printf("\n");
	}
	else for(int i = ind_n; i<n; i++){ // za sa ponavljanjem rekurzija je Komb(i,poz+1) jer ne menjamo brojac i moze se opet koristiti
		komb[ind_k]=a[i]; // dodela vrednosti
		Komb(i+1, ind_k+1); // rekurzija gde sledeci clan je odredjen pomocu brojaca i i pozicija se povecava za jedan
	}
	
}


main(){
	scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++) scanf("%lf", &a[i]);
	Perm(0);
	Var(0);
	Komb(0,0);
}

