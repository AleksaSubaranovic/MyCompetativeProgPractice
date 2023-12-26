// 100% CORRECT
#include<iostream>
using namespace std;

typedef unsigned long long ull;

#define MAX 500000
#define FAIL cout << "NO";
#define YES cout << "YES\n";

ull GetSum(const int& n)
{
    return n*(n + 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr1[MAX];
    int arr2[MAX];

    int n;
    int j = 0;
    int len;
    cin >> n;
    if (GetSum(n) & 1) FAIL
    else if (n == 2) FAIL
    else if (n & 1)
    {
        for (int i = n; i > 3; i-=4)
        {
            arr1[j] = i, arr1[j+1] = i - 3;
            arr2[j] = i - 1, arr2[j + 1] = i - 2;
            j+=2;
        }
        arr1[j] = 3;
        arr2[j] = 1;
        arr2[j + 1] = 2;
        YES
        len = n / 2;
        cout << len << '\n';
        for (int i = 0; i < len; i++) cout << arr1[i] << ' ';
        cout << '\n';
        cout << ++len << '\n';
        for (int i = 0; i < len; i++) cout << arr2[i] << ' ';
    }
    else
    {
        for (int i = n; i > 0; i-=4)
        {
            arr1[j] = i, arr1[j+1] = i - 3;
            arr2[j] = i - 1; arr2[j + 1] = i - 2;
            j+=2; 
        }
        YES
        len = n / 2;
        cout << len << '\n';
        for (int i = 0; i < len; i++) cout << arr1[i] << ' ';
        cout << '\n';
        cout << len << '\n';
        for (int i = 0; i < len; i++) cout << arr2[i] << ' ';
    }
    return 0;
}
