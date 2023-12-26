// analiticka geometrija
#include<stdio.h>
double a,b,c,d,t,x,y;
double a1, b1, c1, d1;
double x1,x2,y1,y2;


main(){
	
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	if(a>b){ // menjamo kordinate tacke da bi mogli da racunamo sa njom
 		t=a; a=b; b=t;}
 	if(c>d){t=c; c=d; d=t;}
 	// pravimo presek
	if(a<c)x = c; // uvek dobija vecu vrednost
	else x = a;
	if(b<d)y = b; // uvek dobija manju vrednost
	else y = d;
	// ako je uslov tacan presek postoji
	if(x<=y)printf("DA %lf %lf", x, y);
	else printf("NE");
	
	// pravougaonik cije su stranice paralelne sa x i y osama se zove BOKS
	// mozemo ga zadati kordinatama dijagonale
	// presek dva boksa
	
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	if(a>b){t = a; a = b; b = t;}
	if(c>d){t = c; c = d; d = t;}
	scanf("%lf%lf%lf%lf", &a1, &b1, &c1, &d1);
	if(a>b){t = a1; a1 = b1; b1 = t;}
	if(c>d){t = c1; c1 = d1; d1 = t;}
	if(a<a1) x1 = a1; // prvi put veca
	else x1 = a;
	if(c<c1) x2 = c; // drugi put manja
	else x2 = c1;
	if(b<b1) y1 = b1;
	else y1 = b;
	if(d<d1) y2 = d;
	else y2 = d1;
	if(x1<=x2 && y1<=y2) printf("presek je %lf %lf i %lf %lf",x1, y1, x2, y2 ); // x1 dobija vecu od dve vrednosti ,a x2 manju I X2 MORA BITI VECA OD X1
	else printf("NE");	
	
}
