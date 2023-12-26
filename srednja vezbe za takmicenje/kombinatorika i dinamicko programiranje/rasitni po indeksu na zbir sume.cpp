#include<stdio.h>

int n, v[100], br[100], S;

void Rasitni(int k, int prS){
	if(k==n){
		if(prS==0){ // ako smo napravili zbir
			for(int i=0; i<n; i++) if(br[i]>0) printf("%d", i); // ispisujemo elemente ako se koriste
			printf("\n-----\n");
		}
	}
	else for(int i=0; i<=1; i++){// clan niza se ili koristi ili ne koristi jer kad je nula onda mnozimo vrednost sa nulom
		br[k] = i;// zapamti broj
		Rasitni(k+1, prS-br[k]*v[k]);// rekurzija gde suma smanjuje za vrednost
	}
}

main(){
	
	scanf("%d%d", &S, &n);
	for(int i = 0; i<n; i++) scanf("%d", &v[i]);
	Rasitni(0, S);
	
}
