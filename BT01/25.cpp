#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if (a < b) swap(a, b);
    if (c < d) swap(c, d);
    if (b < d) swap(b, d);
    swap (d, e);
    if (c < d) swap(c, d);
    if (b < d) swap(b, d);
    if (b < c) cout << b;
    else cout << c;
    return 0;
}
