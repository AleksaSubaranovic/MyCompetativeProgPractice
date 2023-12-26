#include<iostream>
using namespace std;

int w,m,n, n_counter;
int O,best_n,best_m, best_O; // scenario where O is zero

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> w >> m >> n;
	if(n < m) {
		n^=m;m^=n;n^=m; // use n as biggest number
	}
	n_counter = w/n;
	best_O = w;
	if (w%n == 0) cout << "0 * " << m << ' ' << '+'<< n_counter << " * " << n;
	else while(n_counter != -1){ // looping while using larger value as more important one
		O = w - n_counter * n;
		if(O%m == 0){
			cout << O/m << " * " << m << ' ' << n_counter << " * " << n;
			break;
		}
		else {
			if (best_O > O%m) {
				best_O = O%m;
				best_n = n_counter;
				best_m = O/m;
			}
			n_counter--;
		}	
	}
	if(n_counter == -1) cout << best_m << "  " << m << ' ' << best_n << " * " << n;
}
