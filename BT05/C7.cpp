#include <iostream>
using namespace std;

void printLine(int m, int n);

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        printLine(n - i, 2 * (i - 1) + 1);
    }
    return 0;
}

void printLine(int m, int n)
{
    for (int i = 1; i <= m; i++) cout <<' ';
    for (int i = 1; i <= n; i++) cout <<'*';
    cout << endl;
}
