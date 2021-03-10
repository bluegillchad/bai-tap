#include <iostream>
#include <cmath>
using namespace std;

int rnd(double n);

int main()
{
    double n;
    cin >> n;
    cout << rnd(n);
    return 0;
}

int rnd(double n)
{
    if (ceil(n) - n <= n - floor(n)) return ceil(n);
    else return floor(n);
}
