// 100% CORRECT
// note: Subarray's order is important
#include<iostream>
using namespace std;

typedef unsigned long long ull;

int arr[(int)2e5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t; long long rez = 0;
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long sum = arr[0]; int start = 0;
    if (sum == t) rez++;
    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
        if (sum == t) rez++;
        else if (arr[i] == t) start = i + 1, sum = 0, rez++;
        else if (arr[i] > t) start = i + 1, sum = 0;
        else if (sum > t)
        {
            while (sum > t)
            {
                sum -= arr[start];
                start++;
            }
            if (sum == t) rez++;
        }
    }
    cout << rez;
    return 0;
}
