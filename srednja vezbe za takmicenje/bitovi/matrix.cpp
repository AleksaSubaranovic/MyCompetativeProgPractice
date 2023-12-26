//Matriks
#include <stdio.h>
unsigned P(unsigned x){
    if (x%4==0) return x;
    if (x%4==1) return 1;
    if (x%4==2) return x+1;
    return 0;
}
main(){
	unsigned n, m, q, xl, xr, yl, yr;
	scanf("%u%u%u", &n, &m, &q);
	for(int i=0; i<q; i++){
		unsigned rez=0;
		scanf("%u%u%u%u", &xl, &yl, &xr, &yr);
		int dx=xr-xl+1, dy=yr-yl+1;
		if(dx&1) rez=P(yl-1)^P(yr);
		if(dy&1) rez^=P(xl-1)^P(xr);
		printf("%u\n", rez);
	}	
}

