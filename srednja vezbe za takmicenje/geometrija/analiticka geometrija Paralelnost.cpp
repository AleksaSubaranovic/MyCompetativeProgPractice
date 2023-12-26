// uslov paralelnosti duzi, pravi u RAVNI
#include <stdio.h>     
struct Tacka{
	double x, y;
};
main ()
{
	Tacka A1, B1, A2, B2;
 	printf("Unesi x i y koordinate tackaka koje pripadaju 1. pravoj:");
 	scanf("%lf%lf%lf%lf", &A1.x, &A1.y, &B1.x, &B1.y); 
 	printf("Unesi x i y koordinate tackaka koje pripadaju 2. pravoj:");
 	scanf("%lf%lf%lf%lf", &A2.x, &A2.y, &B2.x, &B2.y);
 	if((B2.x-A2.x)*(B1.y-A1.y)==(B1.x-A1.x)*(B2.y-A2.y))printf ("DA");
	else printf("NE");
}
// uslov paralelnosti (b2x-a2x)*(b1y-a1y) == (b1x-a1x)*(b2y-a2y)
// u 3D prostoru jos jedan uslov: (b2x-a2x)*(b1z-a1z) == (b1x-a1x)*(b2z-a2z)

// uslov normalnosti
// if((B1.y-A1.y)*(B2.y-A2.y)==-(B1.x-A1.x)*(B2.x-A2.x)) // na levoj strani proizvodi razlika y osa, a desno x ose sa predznakom -
// u 3D prostoru if(ax*bx+ay*by+az*bz==0)printf("DA"); ako se svi parametri pomnoze i dobije nula 
 
