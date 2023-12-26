#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846
using namespace std;
struct Tacka{
	double x, y, z;
};
Tacka A, B;
double AputaB, intA, intB;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>A.x>>A.y>>A.z>>B.x>>B.y>>B.z;
	AputaB=A.x*B.x+A.y*B.y+A.z*B.z;
	intA=sqrt(A.x*A.x+A.y*A.y+A.z*A.z);
	intB=sqrt(B.x*B.x+B.y*B.y+B.z*B.z);
	cout<<acos(AputaB/(intA*intB))*180/PI;
	return 0;
}
// 5. ????? 

