#include<stdio.h>

bool isComp(int x){
	if (x == 1) return false;  // 1 is not prime or composite
	if(x <=3) return false;
	if(x%2 == 0 || x%3 == 0) return true;
	for(int i = 5; i*i<x; i+=6)
		if(x%i == 0 || x%(i+2) == 0) return true;
	return false;	
}

int a;

main(){
	scanf("%d", &a);
	if(isComp(a)) printf("aha");// slozen
	else printf("nope"); // prost
	
}
