// 100% CORRECT
#include<iostream>
using namespace std;

typedef unsigned long long ull;
#define MAX_SIZE (int)2e5
ull arr[MAX_SIZE];
ull arr2[MAX_SIZE];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ull n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> arr[i];

    // get min element
    ull mini = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] < mini) mini = arr[i];
    mini *= t; // find shortest time needed to get all products made with fastest machine
    
    ull j = 0; // add only machines that can make products before fastest machine finishes
    for (int i = 0; i < n; i++) if (arr[i] <= mini) arr2[j++] = arr[i]; 

    // binary search, "smart" guessing of correct solution
    // here guessing is faster then sorting and calculating
    // O(logN * K), where K is number of "fast machines" (machines that will make at least 1 product before fastest machine finishes alone)
    ull l = 0, r = mini, m, solution; // l,r,m are left, right and mid of time used
    while (l <= r)
    {
        m = l + (r - l)/2;
        ull curr = 0;
        for (int i = 0; i < j; i++) curr += m / arr2[i]; 
        if (curr >= t)
        {
            solution = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << solution;
    return 0;
}
