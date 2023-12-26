// 100% CORRECT
#include<iostream>
using namespace std;

typedef long long ll;

#define MAX_SIZE (int)2e5

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, arr[MAX_SIZE];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll maxSum = (ll)(-1e9), sum = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] <= 0)
        {
            if (sum == 0)
            {
                if (maxSum < arr[i]) maxSum = arr[i]; 
            }
            else if (sum + arr[i] > 0) sum += arr[i];
                else sum = 0;
        }
        else
        {
            sum += arr[i];
            if (sum > maxSum) maxSum = sum;
        }
    }
    cout << maxSum;

    return 0;
}
