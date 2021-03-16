#include <iostream>
using namespace std;

void f(int xval)
{
   int x;
   x = xval;
   cout << &x << endl;
   // in địa chỉ của x tại đây
}
void g(int yval)
{
   int y;
   cout << &y << endl;
   // in địa chỉ của y tại đây
}
int main()
{
   f(7);
   g(11);
   return 0;
}

