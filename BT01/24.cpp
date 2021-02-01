#include <iostream>
using namespace std;
int main()
{
    int ngay, thang, nam;
    long long soNgay = 0;
    cin >> ngay >> thang >> nam;
    int a[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    soNgay += ngay;
    if ( ( (nam % 4 == 0) && (nam % 100 != 0) ) || (nam % 400 == 0) )
    {
        a[2]++;
    }
    for (int i = 0; i < thang; i++) soNgay += a[i];
    nam--;
    soNgay += (nam / 400) * (97 * 366 + 303 * 365);
    nam %= 400;
    soNgay += (nam / 100) * (24 * 366 + 76 * 365);
    nam %= 100;
    soNgay += (nam / 4) * 366 + (nam - nam / 4) * 365;
    switch (soNgay % 7)
    {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;
        case 0: cout << "Sunday"; break;
    }
    return 0;
}


