#include<iostream>
using namespace std;

int a, b;

main(){
	ios::sync_with_stdio(false);
	cin >> a >> b;
	a^=b; //cout << a << b << endl;
	b^=a; //cout << a << b << endl;
	a^=b;
	cout << a << b;
}
