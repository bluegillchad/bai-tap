#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x, y, z, p, S;
    cin >> x >> y >> z;
    p = (x + y + z) / 2;
    S = sqrt(p * (p - x) * (p - y) * (p - z));
    cout << S;
    return 0;
}


