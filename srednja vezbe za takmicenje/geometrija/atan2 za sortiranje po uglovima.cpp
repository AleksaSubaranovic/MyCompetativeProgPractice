#include <iostream>
#include <cmath>
#include <algorithm>
#define PI 3.1415926
using namespace std;
struct Tacka{
	double x, y;
};
double Ugao(Tacka a){
	if(a.x==0){
		if(a.y>0) return 90;
		else return 270;
	}
	if(a.y==0){
		if(a.x>0) return 0;
		else return 180;
	}
	double ugao=atan2(a.y, a.x)*180/PI;
	if(ugao<0) ugao+=360;
	return ugao;
}
bool manjiX(Tacka A, Tacka B){
	return Ugao(A)<Ugao(B);
}
Tacka a[10000];
int n; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i].x>>a[i].y;
	sort(a, a+n, manjiX);
	for(int i=0; i<n; i++) cout<<a[i].x<<","<<a[i].y<<endl;
	return 0;
}

