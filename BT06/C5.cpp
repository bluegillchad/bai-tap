#include <iostream>
using namespace std;

void tong(int n, int k);

int main()
{
    int n;
    cin >> n;
    tong(n , n);
    return 0;
}

void tong(int n, int k)
{
    if (n == 0)
    {
        cout << endl;
        return;
    }
    for (int i = min(n,k); i >= 1; i--)
    {
        cout << i << ' ';
        tong(n - i, i);
    }
}
