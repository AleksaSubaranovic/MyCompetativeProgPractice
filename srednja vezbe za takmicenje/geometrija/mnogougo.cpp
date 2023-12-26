#include<iostream>
#include<cmath>
using namespace std;

struct Kord{
	float x,y;
} niz[50];
int n;

double Formula_Za_MnogoUgo(){
	n--;
	double p;
	for (int i =0, j = 1; i < n; i++, j++) p += niz[i].x * niz[j].y - niz[j].x * niz[i].y;
	p += niz[n + 1].x * niz[0].y - niz[0].x * niz[n + 1].y;
	return fabs(p)/2.00;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> niz[i].x >> niz[i].y;
	cout << Formula_Za_MnogoUgo();
	
	// pripadnost tacke u mnogouglu
	// tokom racunanja povrsine mnogougla racuna se povrsina trougla koji se sastoji od stranica
	// tacke mnogougla do unete tacke, i tacke jedna do druge
	// ako je zavrsni zbir trouglova priblizno isti kao i povrsina mnogougla onda
	// znaci da se ta tacka nalazi u mnogouglu jer sa tom tackom imamo istu povrsinu
	// ako su razliciti onda je tacka van mnogougla
	
	return 0;
}
