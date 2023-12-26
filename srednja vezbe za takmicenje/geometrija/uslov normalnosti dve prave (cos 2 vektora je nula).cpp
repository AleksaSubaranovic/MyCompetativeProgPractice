#include <iostream>
using namespace std;
struct Tacka{
	double x, y;
};
Tacka A1, B1, A2, B2;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
  	cin>>A1.x>>A1.y>>B1.x>>B1.y>>A2.x>>A2.y>>B2.x>>B2.y;
 	if((B1.x-A1.x)*(B2.x-A2.x)+(B1.y-A1.y)*(B2.y-A2.y)==0)  cout<<"DA";
	else cout<<"NE";
	return 0;
}
// valjda moze i samo atan2 pa ako je razlika tacno za 180/PI = 90?
