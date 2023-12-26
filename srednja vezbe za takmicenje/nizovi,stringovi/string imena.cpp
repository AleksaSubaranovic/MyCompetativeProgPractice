#include<iostream>
#include<string> // mozda je potrebno vrv
using namespace std;

main(){
	string niz[100];
	int n, m;
	cin >> n >> m;
	m = m%n;
	// za suprotno od kazaljke m = n-m;
	for(int i = 0; i<n; i++) cin >> niz[i];
	for(int i = 0; i<n; i++) if(i != m) cout << niz[i] << " ";
							
	
	
}
