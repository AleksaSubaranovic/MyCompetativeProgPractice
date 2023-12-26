// 6of7, check Room_AllocationWithMap.cpp
#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;

struct room
{
    unsigned start, end, customer;
};

room arr[(int)2e5];
int res[(int)2e5];
room customers[(int)2e5];

bool compare(const room& a, const room& b)
{
    if (a.start < b.start) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; i++) { cin >> customers[i].start >> customers[i].end; customers[i].customer = i; }

    sort(customers, customers + n, &compare);

    // first room
    arr[0] = customers[0];
    int k = 1;
    res[customers[0].customer] = 1;

    for (int i = 1; i < n; i++)
    {
        int check = 0;
        while (check < k)
        {
            if (customers[i].start > arr[check].end)
            {   
                arr[check].end = customers[i].end;
                res[customers[i].customer] = check + 1;
                break;
            }
            check++;
        }
        if (check == k) 
        {
            arr[k] = customers[i]; k++;
            res[customers[i].customer] = k;
        }
    }
    cout << k << '\n';
    for (int i = 0; i < n; i++) cout << res[i] << ' ';


    return 0;
}
