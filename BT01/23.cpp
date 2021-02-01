#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int x, y, tong, hieu;
    cin >> x >> y;
    tong = x + y;
    hieu = abs(x - y);
    cout << (tong + hieu) / 2;
    return 0;
}


