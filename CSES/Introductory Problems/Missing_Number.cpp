// 100% CORRECT
#include<iostream>
using namespace std;

#define ll long long

int GetXor(int number)
{
    if (number % 4 == 0) return number;
    if (number % 4 == 3) return 0;
    if (number % 4 == 2) return number + 1;
    else return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int input;
    int temp = 0;
    int n;
    cin >> n; n--;
    for (int i = 0; i < n; i++) 
    {
        cin >> input;
        temp ^= input;
    }
    
    temp =  GetXor(n + 1) ^ temp;
    cout << temp;

    return 0;
}
