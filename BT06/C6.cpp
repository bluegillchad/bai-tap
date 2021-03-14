#include <iostream>
using namespace std;

int* print(int n);

int main()
{
    int n;
    int *a = print(n);
    for (int i = 0; i < n; i++) cout << a[i];
    return 0;
}

int* print(int n)
{
    int a[3];
    for (int i = 0; i < n; i++) a[i] = i;
    return a;
}
