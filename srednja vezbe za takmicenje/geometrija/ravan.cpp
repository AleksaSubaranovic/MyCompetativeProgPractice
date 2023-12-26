#include<stdio.h>
struct Line{
	long long id,pres,x1,x2,y1,y2;
      	double k;
};
void Komb(int poz,int start, int n, Line a[], Line komb[]){
     	if(poz==2){
		if((komb[0].x2-komb[0].x1)*(komb[1].y2-komb[1].y1)!=(komb[1].x2-komb[1].x1)*(komb[0].y2-komb[0].y1)) a[komb[1].id].pres++;
     	}
     	else for (int i=start;i<n;i++){
          		komb[poz]=a[i];
          		Komb(poz+1,i+1,n,a,komb);
     	}
}
int main(){
	long long n;
   	unsigned long long br=0;
	scanf("%lld",&n);
	Line A[n];
	for(long long i=0;i<n;i++){
    		scanf("%lld%lld%lld%lld",&A[i].x1,&A[i].y1,&A[i].x2,&A[i].y2);
        		A[i].id=i;
        		A[i].pres=1;  
    	}
   	if(n==1)br=2;
    	else{        		
    		br=1;    		
		Line komb[2];
		Komb(0,0,n,A,komb);
		for (long long i=0;i<n;i++)br+=A[i].pres;
    }
    printf("%llu",br%1000003);
    return 0;
}

