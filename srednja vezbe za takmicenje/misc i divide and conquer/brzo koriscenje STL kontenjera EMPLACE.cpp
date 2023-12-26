#include<iostream>
#include<queue>
using namespace std;

main(){
	queue<int>q;
	q.push(1);
	q.emplace(8);
	cout << q.front();
	q.pop();
	cout << q.front();
}
