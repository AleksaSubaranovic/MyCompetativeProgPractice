#include<iostream>
#include<stack> // for multiple bracket types
using namespace std;

typedef unsigned long long ull;

// one type of bracket
bool isBalanced(const string& s)
{
    int balance = 0;
    for (auto i : s) 
    {
        if (i == '(') balance++;
        else balance --;
        if (balance < 0) return false;
    }
    if (balance == 0) return true;
    else return false; 

}

// multiple types of brackets
bool isBalanced2(const string& s)
{
    stack<char> st;
    for (auto i : s)
    {
        if (i == '{' || i == '[' || i == '(') st.push(i); // if order of oppening brackets matter check that as well
        else if (st.empty()) return false;
        else switch (i)
        {
            case ')' : if (st.top() == '(') st.pop(); else return false;
            break;
            case ']' : if (st.top() == '[') st.pop(); else return false;
            break;
            case '}' : if (st.top() == '{') st.pop(); else return false;
            break;
        }
    }
    if (st.size() == 0) true;
    else return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    string a, b;

    cout << "Enter bracket sequence with 1 bracket type\n";
    cin >> a;

    if (isBalanced(a)) cout << "Inputed string is balanced.\n";
    else cout << "Inputed string is not balanced\n";

    cout << "Enter bracket sequence with 3 bracket types\n";
    cin >> b;

    if (isBalanced2(b)) cout << "Inputed string is balanced.\n";
    else cout << "Inputed string is not balanced\n";

    return 0;
}
