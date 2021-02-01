#include <iostream>
using namespace std;
int main()
{
    int x, y, z;
    bool b;
    cin >> x >> y >> z;
    if ( ( (x > y) && (y > z) ) || ( (x < y) && (y < z) ) ) b = true;
    else b = false;
    if (b) cout << "true";
    else cout << "false";
    return 0;
}

