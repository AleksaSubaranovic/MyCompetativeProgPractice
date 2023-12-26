// Sistemi (Binarni, Dekadni itd...)
#include<iostream>
using namespace std;


int main(){
	int n, B, a[15], broj=0, i; // n = br. cifara, B = sistem, b[] = cifre, a = konacan rezultat
	cin >> n >> B ; 
	for(i=n-1;i>=0;i--)cin >> a[i];
	for(i=n-1;i>=0;i--)broj=broj*B+a[i]; // npr (34)5 = broj*5+3>>3*5+4>>19
	cout << broj; 
	int b[15], m = 0, C; // b[] = niz cifara za C sistem, m = broj cifara za C sistem	
	cin >> C;
	while(broj>0){
		b[m]=broj%C; // ostatak deljenja sa C
		broj=broj/C; // podelimo broj
		m++; // broj cifara
	}
	for(int i = m-1; i>=0; i--) cout << b[i];

	
}
