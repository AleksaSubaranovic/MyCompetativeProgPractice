// 100% CORRECT
#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    unsigned int a = 1, c = 1, g = 1, t = 1;
    unsigned int temp = 0;
    cin >> s;
    int n = s.length();
    
    int j, len;

    for (int i = 0; i < n; i++)
    {
        for (j = i + 1; j < n && s[j] == s[i]; j++) {}
        len = j - i;
        if (len > 1)
        switch (s[i])
        {
            case 'A' : if (len > a) a = len; break;
            case 'C' : if (len > c) c = len; break;
            case 'G' : if (len > g) g = len; break;
            case 'T' : if (len > t) t = len; break;
        }
        i = j - 1;
    }

    cout << max(a, max(c, max(g, t)));
    return 0;
}
