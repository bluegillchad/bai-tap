#include <iostream>
using namespace std;

int findGCD (int a, int b);

int main()
{
    int a,b;
    cin >> a >> b;
    if (findGCD(a,b) == 1) cout << "Yes";
    else cout << "No";
    return 0;
}

int findGCD (int a, int b)
{
    if (a < b) swap (a,b);
    while (a % b != 0)
    {
        a %= b;
        swap (a,b);
    }
    return b;
}
