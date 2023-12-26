#include<iostream>
#include<queue>
using namespace std;

int Q; // ogranicenje 500000
char a,b; // a = 1 ili 2 // b = uneti karakter
queue <char> L,D; // leva i desna polovina
bool paran; // uslov parnosti
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> Q;
	
	for (int i = 0; i<Q; i++){
		cin >> a;
		if (a == '1'){
			cin >> b;
			D.push(b);
			if (paran){
				L.push(D.front()); // na kraj leve polovine se ubacuje prvi karakter desne polovine
				D.pop(); // izbacuje se taj karakter da ne bi postojao dva puta
			}
			paran = !paran; // svaki drugi put ce se prebaciti karakter u drugu polovinu
		}
		else {
			swap(L,D);
		}
	}
	
	while(!L.empty()){
		cout << L.front();
		L.pop();
	}
	while(!D.empty()){
		cout << D.front();
		D.pop();
	}
	
}
