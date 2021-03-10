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
    int N = n;
    if (N + 1 - n <= n - N) return N + 1;
    else return N;
}
