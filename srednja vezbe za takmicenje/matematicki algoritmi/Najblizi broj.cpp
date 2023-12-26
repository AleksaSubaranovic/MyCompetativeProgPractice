#include<stdio.h>
#include<math.h>
main(){
	long long n,n1,najbl1=0,najbl2=0; int a[18],i,j,m=0; bool neop=true;
	scanf("%lld", &n);
	n1=n;
	while(n>0){
		a[m]=n%10;
		n=n/10;
		m++;
	}
	for(i=m-1;i>0;i--) if(a[i]>a[i-1]){ // da li opada
		neop=false;
		break;
	}
	if(!neop){ // ako opada
		for(j=i-1;j>=0;j--) a[j]=a[i]; //  cifre od pocetka opadanja postaju jednake prvoj cifri
		for(j=m-1;j>=0;j--) najbl1=najbl1*10+a[j];	// racuna novi broj
	}
	a[i]--; // za broj ispod
	while(i+1<m && a[i+1]>a[i]){
	 a[i-1]--;
	 i++;
	}
	for(j=i-1;j>=0;j--) a[j]=9;
	for(j=m-1;j>=0;j--) najbl2=najbl2*10+a[j];
	if(neop)printf("%lld", n1);
	else if(najbl1-n1<n1-najbl2)printf("%lld", najbl1);
	else if(najbl1-n1>n1-najbl2)printf("%lld", najbl2);
	else printf("%lld %lld", najbl1,najbl2);
}
