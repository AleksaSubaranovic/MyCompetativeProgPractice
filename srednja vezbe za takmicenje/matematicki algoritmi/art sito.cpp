#include<stdio.h>
#include<stdlib.h>
main(){
	int n, i, j; bool slozen[1000]={false, false, false}; 
	scanf("%d", &n);
	for(i=2;i<=n;i++) if(!slozen[i]){
		printf("%d ", i);
		for(j=i;j<=n;j+=i) slozen[j]=true;
	}
	system("pause");
}
