// 100% CORRECT
// FOR MORE INFO SEE https://www.purplemath.com/modules/factzero.htm
// solution is number of "5 X 2"s, 10X1 == 2 X 5 X 2 
// for every power of 5 included there is 5 X 2
// when there is 5, there has to be number of factor 2
// example 1 X 2 X 3 X... 20
// 5 X 2, 10 X 4(2X2),15 X 6(2X3),20 X 8(2X4), there is always 2 for 5
// example 1 X 2 X 3 X.. 100
// 100/5 = 20; 25,50,75,100 are 5X5 X K(1,2,3,4), so we have extra 5
// every power of 5 adds another 5 to product. 
#include<iostream>
using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ull n;
    ull zeros = 0;
    ull fives = 5;
    cin >> n;
    if (n >= 5)
    while (n >= fives)
    {
        zeros += n/fives;
        fives *= 5;
    }
    cout << zeros;

    return 0;
}
