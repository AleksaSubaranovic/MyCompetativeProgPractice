// rasitni broj na 2 mnozioca
#include<stdio.h>

int n, v[100], br[100], S; // v je niz vrednosti mnozilaca a br je niz koji predstavlja koliko puta se koristi koja novcanica

void Rasitni(int k, int prS){
	if(k==n){ // ako smo rasitnili na trazeni broj mnozilaca
		if(prS==0){ // da li smo rasitnili
			for(int i=0; i<n; i++) printf("%d novcanica od %d din\n", br[i], v[i]);
			printf("\n------\n");
		}
	}
	else for(int i=0; i<=prS/v[k]; i++){
		br[k] = i;// broj koji pokazuje koliko puta se koristi jedan mnozilac
		Rasitni(k+1, prS-br[k]*v[k]); // rekurzija
	}
}

main(){
	
	scanf("%d%d", &n, &S);
	for(int i = 0; i<n; i++) scanf("%d", &v[i]);
	Rasitni(0, S);
	
}
