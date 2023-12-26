#include<iostream>
#include<utility>
#include<list>
using namespace std;

int N, a;
pair<int, int> A[1000];
bool sloz[200000];
list<int>prost_niz;
bool used[200000];
int B[1000]; bool failled;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a, A[i] = make_pair(a,i);
	
	// Eratostenovo sito
	for (int i = 2; i <= A[N-1].first; i++) if (!sloz[i]){;
		prost_niz.push_back(i);
		for (int j = i + i; j <= A[N-1].first; j += i) sloz[j] = true;
	}

	for (int i = 0; i < N; i++){
		failled = true;
		for (auto it = prost_niz.begin(); it != prost_niz.end() && (*it) <= A[i].first; it++)
			if (A[i].first % (*it) == 0 && !used[A[i].first / (*it)]){
				used[A[i].first / (*it)] = true;
				B[A[i].second] = *it;
				failled = false;
				break;
			}
		if (failled){
			cout << "-1"; return 0;
		}	
	}
	
	for (int i = 0; i < N-1; i++) cout << B[i] << ' ';
	cout << B[N-1]; 	
	return 0;
}
