// 100% CORRECT
#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;
int arr[200000];
int n;
int LengthOfLIS()
{
    int tail[200000];
    int tail_length = 1;
    tail[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < tail[0]) tail[0] = arr[i]; 
        else if (arr[i] > tail[tail_length - 1]) tail[tail_length++] = arr[i];
        else tail[lower_bound(tail, tail + tail_length, arr[i]) - tail] = arr[i];  
    }
    return tail_length;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << LengthOfLIS();
    return 0;
}
