#include<stdio.h>

char niz[10], *a, *b;
bool op = false;
int A, B;
int main() {
	// unos
	scanf("%s", niz);
	
	a = niz;
	while(*(a+1) != '\0') if(*a > *(a+1)) {
		op = true;
		b = a;
		break;
	}
	else a++;
	if(op) {
		const char cifra = *a;
		
			A = A * 10 + *a - 48;
			B = B * 10 +  cifra - 48;
			(*a)--;
			a++;
			
		while(*a != '\0'){
			A = A * 10 + *a - 48;
			B = B * 10 +  cifra - 48;
			*a = '9';
			a++;
			printf("%d %d\n", A,B);
		}
		if(B - A < A%10 + 1) for(char* ptr = niz; *ptr != '\0'; ptr++) 
							if(ptr != b) printf("%c", *ptr);
							else { printf("%d", B); break; }		
		else for(char* ptr = niz; *ptr != '\0'; ptr++) printf("%c", *ptr);
				
				
	}
	else printf("%s", niz);
	
	return 0;
}
