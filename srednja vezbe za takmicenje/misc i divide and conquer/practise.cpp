#include<stdio.h>
#include<list>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
main(){
	int n; string a;
	vector<string> s;
	vector<string>::iterator it;
	cin >> n;
	for(int i = 0; i<n; i++){
	cin >> a;
	s.push_back(a);
	}
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	for(it = s.begin(); it != s.end() ; it++)
	cout << *it << ' ';
	
}
