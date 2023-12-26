#include<stdio.h>

#include <stdlib.h>

#include <algorithm>
// bool binary_search(a,a+n,x)
int BinarySearch(int l, int d, double x, double a[]){ // trazi se indeks x-a u nizu a
	while(l<=d){
		int s=l+(d-l)/2;
		if(a[s]==x) return s; // provera da li je x na sredini
		if(a[s]<x) l=s+1; // ako je x vece od elementa na sredini, ignorisi levu polovinu
		else d=s-1; // ako je x manje, ignorisi desnu polovinu
	}
	return -1;
}
int brPoj(int n, double x, double a[]){
	int ind=BinarySearch(0, n-1, x, a);
	if(ind==-1) return 0; // ako element nije prisutan
	int br=1, l=ind-1, d=ind+1;
	while(a[l]==a[ind]){ // broji pojavljivanja sa leve strane
		br++;
		l--;
	}
	while(a[d]==a[ind]){ // broji pojavljivanja sa desne strane
		br++;
		d++;
	}
	return br;
}

using namespace std;
main(){
	int n; double a[10], x;
	scanf("%d", &n);
	for(int i=0; i<n; i++)scanf("%lf", &a[i]);
	scanf("%lf", &x);

	printf("%d", brPoj(n, x, a));
}


