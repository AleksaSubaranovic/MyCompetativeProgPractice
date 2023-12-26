#include<iostream>
#include<set>
using namespace std;

typedef unsigned long long ull;

int n;
string s;
char var[10];
bool used[10];
set<string> st;
string temp;

void Perm(int index)
{
    if (index == n)
    {
        temp.clear();
        for (int i = 0; i < n; i++) temp+=var[i];
        st.insert(temp);
    }
    else for (int i = 0; i < n; i++) if (!used[i])
    {
        var[index] = s[i];
        used[i] = true;
        Perm(index + 1);
        used[i] = false;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s; for (int i = 0; i < 10; i++)
    n = s.length();

    Perm(0);

    cout << st.size() << '\n';
    for (auto it : st) cout << it << '\n';

    return 0;
}
