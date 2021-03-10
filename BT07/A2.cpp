#include <iostream>
using namespace std;
void test(int a[])
{
    cout << sizeof(a);
}
int main()
{
    int a[5];
    cout << sizeof(a) << endl;
    test(a);
    return 0;
}

