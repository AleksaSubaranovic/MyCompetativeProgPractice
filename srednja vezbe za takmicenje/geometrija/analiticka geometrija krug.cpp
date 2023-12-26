// krug
// (x-x0)^2 +(y-y0)^2 = R^2.
// da bi tacka x,y pripadala krugu mora da njeno rastojanje od centra kruga manje od poluprecnika kruga (x-x0)^2 +(y-y0)^2 <= R^2.


#include<stdio.h>
#include<math.h>

struct Kord{
	double x, y;
};

Kord a,b, c;
double r, D,A,B,C, t1, t2;

main(){
	/*scanf("%lf %lf", &a.x, &a.y );
	scanf("%lf %lf %lf", &c.x, &c.y, &r);
	if(((a.x-c.x)*(a.x-c.x) + (a.y-c.y)*(a.y-c.y)) <= r*r) printf("U krugu je");
	else printf("Nije");
	*/
	// (ax + t * (bx - ax) - x0 )^2 + (ay + t * (by - ay) - y0 )^2 = r^2
	// A* (t^2) · B*t + C = 0 
	// A = (bx - ax)^2 + (by - ay)^2; B = 2((bx-ax)*(ax-x0) + (by - ay)*(ay-0y)); C = (ax - x0)^2 + (ay-0y)^2 - r*r
	printf("krug i prava");
	scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
	scanf("%lf%lf%lf", &c.x, &c.y, &r);
	printf("USPEH");
	A = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
	B = 2*((b.x-a.x)*(a.x-c.x) + (b.y - a.y)* (a.y - c.y));
	C = (a.x-c.x)*(a.x-c.x) + (a.y - c.y)*(a.y - c.y) - r*r;
	D = B*B-4*A*C;
	if(D>0){
		D = sqrt(D);
		t1 = (-B + D)/2*A;
		t2 = (-B - D)/2*A;
		printf("Seku se u %lf %lf i %lf %lf", a.x+t1*(b.x-a.x), a.y+t1*(b.y-a.y), a.x+t2*(b.x-a.x), a.y+t2*(b.y-a.y));
	}
	else if(D == 0){
		t1 = -B/(2*A);
		printf("Seku se u %lf %lf", a.x+t1*(b.x-a.x), a.y+t1*(b.y-a.y));
	}
	else printf("Nema resenja");

}
