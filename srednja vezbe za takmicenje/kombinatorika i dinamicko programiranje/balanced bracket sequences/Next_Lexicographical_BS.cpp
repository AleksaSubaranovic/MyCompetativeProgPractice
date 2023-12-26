#include<iostream>
using namespace std;

typedef unsigned long long ull;

string NextBalancedSequence(string s)
{
    int depth = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '(') depth--;
        else depth++;
        if (s[i] == '(' && depth > 0)
        {
            s = s.substr(0, i) + ')';
            int x = (n - 1 - i - (depth - 1)) / 2; // because there are more open brackets on left side
            s += string(x, '(') + string(n - 1 - i - x, ')');
            return s;
        }
    }
    return string("0");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    cin >> a;
    a = NextBalancedSequence(a);
    if (a != "0") cout << a;

    return 0;
}
