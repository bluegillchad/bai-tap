#include <iostream>
using namespace std;

int main( )
{
   int a[4] = {1,2,3,4};
   for (int *cp = a; (*cp) != NULL; cp++) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
}

