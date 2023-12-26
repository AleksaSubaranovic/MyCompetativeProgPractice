#include<iostream>
using namespace std;

char S[100];
int l,r,swap_counter,swap_length, i;
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> S;
	for(i=0;S[i]!='\0';i++){
		if(S[i] == '['){
			l++;
			if(swap_length > 0){
				swap_counter+= swap_length;
				swap_length--;
			}
		}
		else {
			r++;
			if(r > l) swap_length = r-l;
		}
	}
	cout << swap_counter;
}
