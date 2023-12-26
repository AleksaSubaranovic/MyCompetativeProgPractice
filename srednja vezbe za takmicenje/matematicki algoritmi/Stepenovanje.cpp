// stepenovanje
#include<stdio.h>
#include<stdlib.h>
double St(double x, int n){
	if(n==0) return 1; // stepen 0
	if(n==1) return x; // stepen 1
	if(n%2==0) return St(x*x, n/2); // rekurzija ako je stepen paran
	else return x*St(x*x,n/2); // ako nije stepen paran rekurzija sa pomnozenim x
}

main(){
	double x; int n;
	scanf("%lf%d", &x, &n);
	printf("%lf", St(x,n));
	system("pause");
}
