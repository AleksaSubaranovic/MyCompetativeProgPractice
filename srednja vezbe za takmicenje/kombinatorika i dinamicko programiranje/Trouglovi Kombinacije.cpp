#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double p=0;
void Komb(int poz, int start, int n, int a[],int komb[], int k, double x[], double y[]){
	if(poz==k){
		double x1=x[komb[0]], y1=y[komb[0]], x2=x[komb[1]], y2=y[komb[1]], x3=x[komb[2]], y3=y[komb[2]];// x1,y1... dobijaju vrednosti na osnovu x[]y[] koje koriste komb[]
																						// koji sadrzi indekse tj nic komb[] cuva indekse koje uzimamo za nizove x[] i y[]
		if(x1*x2>0 && y1*y2>0)return;//uslovi da proverimo da li su sve tacke u razlicitim kvadrantima
		if(x1*x3>0 && y1*y3>0)return;
		if(x2*x3>0 && y2*y3>0)return;
		double s1=sqrt(pow(x1-x2,2)+pow(y1-y2,2)), s2=sqrt(pow(x2-x3,2)+pow(y2-y3,2)), s3=sqrt(pow(x3-x1,2)+pow(y3-y1,2)); // racunamo povrsinu trougla
		double s=(s1+s2+s3)/2;
		p+=sqrt(s*(s-s1)*(s-s2)*(s-s3));
			
	}
	else for(int i=start;i<n;i++){
		komb[poz]=a[i];
		Komb(poz+1,i+1,n,a,komb,k,x,y);
	}
}

main(){
	int n,k=3,komb[3]; int *a; double *x, *y;
	scanf("%d", &n);
	a=(int*)calloc(n, sizeof(int));
	x=(double*)calloc(n,sizeof(double));
	y=(double*)calloc(n,sizeof(double));
	for(int i=0;i<n;i++){
		a[i]=i;
		scanf("%lf%lf", &x[i], &y[i]);
		
		
	}
	Komb(0,0,n,a,komb,k,x,y);
	printf("%lf", p);
}
