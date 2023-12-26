// 100% CORRECT
#include<iostream>
using namespace std;

#define ll long long

const int MAX = (int)2e5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int array[MAX];
    unsigned int n;
    cin >> n;
    unsigned ll rez = 0;
    for (int i = 0; i < n; i++) cin >> array[i];
    for (int i = 1; i < n; i++) if (array[i - 1] > array[i]) 
    {
        rez += array[i - 1] - array[i];
        array[i] = array[i - 1];
    }
    cout << rez;
    return 0;
}
