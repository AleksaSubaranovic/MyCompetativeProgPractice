#include<stdio.h>
int np,nm,nk,lp,lk,lm; // unsigned
int rez;
main(){
	scanf("%d%d%d", &np, &nk, &nm);
	scanf("%d%d%d", &lp, &lk, &lm);
		if((lp*2 - nk) >= 0 && nk != 0)
		{
			rez += nk;
			lp = (lp*2 - nk) /2;
			nk = 0; 
		}
		else 
		{
			rez += lp * 2;
			nk -= lp *2;
			lp = 0;
		}
		
		if((lk*2 - nm) >= 0 && nm != 0)
		{
			rez += nm;
			lk = (lk*2 - nm) /2;
			nm = 0; 
		}
		else 
		{
			rez += lk * 2;
			nm -= lk *2;
			lk = 0;
		}
		
		if((lm*2 - np) >= 0 && np != 0)
		{
			rez += np;
			lm = (lm*2 - np) /2;
			np = 0; 
		}
		else 
		{
			rez += lm * 2;
			np -= lm *2;
			lm = 0;
		}
		printf("%d ",rez);
		if(lp > 0 && np > 0) if(lp >= np){
			rez += lp = lp-np;
			np = 0;
		}
		else
		{
			rez += np = np - lp;
			lp = 0;
		}
		
		if(lk > 0 && nk > 0) if(lk >= nk){
			rez += lk = lk-nk;
			nk = 0;
		}
		else
		{
			rez += nk = nk - lk;
			lk = 0;
		}
		
		if(lm > 0 && nm > 0) if(lm >= nm){
			rez += lm = lm-nm;
			nm = 0;
		}
		else
		{
			rez += nm = nm - lm;
			lm = 0;
		}
		printf("%d ",rez);
		if(lp > 0 && nm > 0) if(lp/2 >= nm)
			rez += nm;
			else rez += lp/2;
		if(lk > 0 && np > 0) if(lk/2 >= np)
			rez += np;
			else rez += lk/2;
		if(lm > 0 && nk > 0) if(lm/2 >= nk)
			rez += nk;
			else rez += lm/2;
				printf("%d ",rez);
}
