// 100% CORRECT
#include<iostream>
#include<map>
using namespace std;
 
typedef unsigned long long ull;
int arr[(int)2e5];
map<int, int>mp;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++) cin >> arr[i];
    
    cout << 0 << ' ';
    mp.emplace(make_pair(arr[0], 0));

    for (int i = 1; i < n; i++)
    {
        if (mp.begin()->first >= arr[i]) // if new element is smallest then there is no element smaller before
    {                                    // therfore all elements before are removed, and current one is added as smallest
            cout << "0 ";
            mp.clear();
            mp.emplace(make_pair(arr[i], i));
        }
        else if (arr[i - 1] < arr[i]) // fast check if prev element is smaller, small "optimization"
        {
            cout << i << ' ';
            mp.emplace(make_pair(arr[i], i));
        }
        else // going threw all elements smaller then current one and finding closest one to current position
        {    // and deleting all elements greater than current one, because all of these elements are larger and further away from any next added element
            map<int, int>::iterator it1, it2 = mp.lower_bound(arr[i]);
            it1 = it2; it1--;
            if (it2 != mp.end()) mp.erase(it2, mp.end());

            int j = it1->second;
            for (;it1 != mp.begin(); it1--) if (j < it1->second) j = it1->second;
            if (mp.begin()->second > j) j = mp.begin()->second;
            cout << j + 1 << ' ';
            mp.emplace(make_pair(arr[i], i));
        }
    }

    return 0;
}