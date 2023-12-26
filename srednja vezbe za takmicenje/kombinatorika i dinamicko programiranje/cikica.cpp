#include <bits/stdc++.h>
struct Pos{
	int x, y;
};
Pos Put[100];
int n, a[10][10], stx, sty, endx, endy, min=101;
int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
void IdiNa(int k, int x, int y){
	if(!(x>=0 && x<n && y>=0 && y<n && (a[x][y]==0 || a[x][y]==2 || a[x][y]==3)))return;
	a[x][y]=-1;
	Put[k].x=x; Put[k].y=y;
	if(x==endx && y==endy){
		if(k<min) min=k;
		for(int i=0; i<=k; i++)printf("(%d,%d)", Put[i].x, Put[i].y);
		printf("\n");
	}
	else for(int i=0; i<4; i++)IdiNa(k+1,x+dx[i], y+dy[i]);
	a[x][y]=0;
}
main(){
   scanf("%d", &n);
   for(int i=0; i<n; i++)
   		for(int j=0; j<n; j++){
   			scanf("%d", &a[i][j]);
   			if(a[i][j]==3){
   				stx=i;
   				sty=j;
   			}
   			else if(a[i][j]==2){
   				endx=i;
   				endy=j;
   			}
   		}
   	IdiNa(0,stx,sty);
   	if(min==101)printf("Cikica se ostati gladan");		
}

