#include <iostream>
#include <cmath>
using namespace std;

bool checkPrime (int n);

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (checkPrime(i)) cout << i << endl;
    }
    return 0;
}

bool checkPrime (int n)
{
    if (n == 1) return false;
    bool chck = true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) chck = false;
    }
    return chck;
}
