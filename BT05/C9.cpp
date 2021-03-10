#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int n);

int main()
{
    srand(time(0));
    int n;
    cin >> n;
    cout << random(n);
    return 0;
}

int random(int n)
{
    return rand() % n;
}
