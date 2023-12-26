// 100% CORRECT
#include<iostream>
#include<unordered_map>
using namespace std;

typedef unsigned long long ull;

void AddChars(string& solution, char c, int number)
{
    while(number--) solution+=c;
}

string MakePalindrome(string solution, char X)
{
    string temp = solution;
    if (X != '0') temp += X;
    for (int i = solution.length() - 1; i >= 0; i--) temp += solution[i];
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<char, unsigned int>map;
    for (char c = 'A'; c <= 'Z'; c++) map.insert(make_pair(c, 0));

    string s;
    cin >> s;
    for(char& c : s)
    {
        map[c]++;
    }
    bool odd = s.length() & 1;
    char X = '0';
    string solution;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (map[c] & 1)
            if (odd) odd = false, X = c, AddChars(solution, c, map[c]/2);
            else {
                cout << "NO SOLUTION";
                return 0;
            } 
        else AddChars(solution, c, map[c]/2);
    }

    cout << MakePalindrome(solution, X);
    return 0;
}
