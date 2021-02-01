#include <iostream>
using namespace std;
int main()
{
    string s0 = "a", s1 = "b";
    cout << s0 << endl << s1 << endl;
    for (int i = 2; i <= 10; i++)
    {
        s0 = s1 + s0;
        swap(s0,s1);
        cout << s1 << endl;
    }
    return 0;
}

