// 100% CORRECT
#include<iostream>
#include<unordered_set>
using namespace std;

typedef unsigned long long ull;

unordered_set<ull> set;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ull n;
    cin >> n; ull X;
    set.reserve(n); // needed fo 100% CORRECT
    for (ull i = 0; i < n; i++) {cin >> X; set.emplace(X);}
    cout << set.size();
    return 0;
}
