// trivijalan broj
#include<stdio.h>
#include<math.h>
main(){
	int T,i,a[10],j,k,najt; bool prost; int koren; // T = broj unesenih vrednosti
	scanf("%d", &T);
	for(i=0;i<T;i++)scanf("%d", &a[i]);
	for(i=0;i<T;i++) if(a[i]==2 || a[i]==3) najt=a[i]; // odmah nalazimo prost ako je 2 ili 3 jer su najmanji
					else for(j=a[i];j>=2;j--){
						prost=true; koren=(int)sqrt(j);
						for(k=2;k<=koren;k++) if(j%k==0){
							prost=false;
							break;
						}
						if(prost){
							najt=j;
							break;
						}	
					} printf("%d\n", najt);
	
	
}
