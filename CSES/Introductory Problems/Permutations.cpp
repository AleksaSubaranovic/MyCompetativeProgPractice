// 100% CORRECT 
#include<iostream>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n;
    cin >> n;
    if (n < 4 && n != 1) cout << "NO SOLUTION";
    else if (n == 1) cout << 1;
    else if (n == 4) cout << "2 4 1 3"; // edge case
    else 
    {
        for (int i = 1; i <= n; i+=2) cout << i << ' ';
        for (int i = 2; i <= n; i+=2) cout << i << ' ';
    }
    return 0;
}
