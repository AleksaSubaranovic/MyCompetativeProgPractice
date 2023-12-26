// NZD NZS 
#include<stdio.h>
#include<stdlib.h>
int NZD(int a, int b){ // rekurzija za NZD     formula je da je to rekurzija modua
	 b == 0 ? return a : return NZD(b, a%b);
}

main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", NZD(a,b));
	int A[10], n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++) scanf("%d", &A[i]);
	int nzd = NZD(A[0], A[1]);
	for(int i = 2; i<n; i++) nzd = NZD(nzd, A[i]);
	printf("%d", nzd);
}
/*
NZS = a*b/NZD(a,b);

za niz:
nzs = a[0]*a[1]/NZD(a[0], a[1]);
for(int i = 2; i<n; i++) nzs = nzs*a[i]/NZD(nzs, a[i]);
*/

