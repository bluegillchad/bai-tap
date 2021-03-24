#include <iostream>
using namespace std;
int main()
{
    int* p = new int;
    int* p2 = p;
    *p = 10;
    delete p;
    *p2 = 100; // tro vao vung nho cua p la con tro nhung da bi xoa
    cout << *p2;
    delete p2; // delete con tro khong tao tu new
}
