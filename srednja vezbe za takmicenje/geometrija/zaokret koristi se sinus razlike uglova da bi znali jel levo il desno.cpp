#include <iostream>
using namespace std;
struct Tacka{
	double x, y;
};
Tacka P, Q, R;
double razlPovrsina;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>P.x>>P.y>>Q.x>>Q.y>>R.x>>R.y;
	razlPovrsina=(Q.x - P.x) * (R.y - P.y) - (R.x - P.x) * (Q.y - P.y);
	if(razlPovrsina>0) cout<<"L";
	else if(razlPovrsina<0) cout<<"D";
	else cout<<"K";
	return 0;
}

