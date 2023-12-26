// geometrija prave , kurga itd..
// x = ax + t*(bx-ax), y = ay + t*(by-ay) je jednacina za prikaz prave  A(ax,ay) B(bx,by) i M(x,y)
// t je parametar koji ako je jednak nuli daje A, a ako je jednak jedinici daje B
// te je prava kad je t[-inf, +inf]
#include<stdio.h>
double t1,t2;
struct Kord{
	double x, y;
};
Kord a,b,c,d;

main(){
	scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
	scanf("%lf%lf%lf%lf", &c.x, &c.y, &d.x, &d.y);
	//  ax + t1*(bx-ax) = cx + t2*(dx-cx) &&  ay + t1*(by-ay) = cy + t2*(dy-cy) napravimo sistem i racunamo 
	t2 = ((c.y-a.y)*(b.x-a.x)+a.x-c.x)/((d.x-c.x)*(b.y-a.y)-(b.x-a.x)*(d.y-c.y));
	t1 = (c.x-a.x+t2*(d.x-c.x))/(b.x-a.x);
	if(t1>=0 && t2>=0 && t1<=1 && t2<=1) printf("USPESNA MISIJA %lf %lf", t1, t2);
	else printf("nope");

	
}

