#include <iostream>
using namespace std;

int timnhiphan(int *arr, int n, int key)
{
    int low = 0, high = n-1, mid = (n-1)/2;
    while (low <= high)
    {
        if (*(arr + mid) == key) return mid;
        else if (*(arr + mid) < key) low = mid + 1;
        else high = mid - 1;
        mid = (low + high) / 2;
    }
    return -1;
}
int main()
{
    int a[10] = {1,3,5,7,9,11,13,15,17,19};
    cout << timnhiphan(a,10,20);
    return 0;
}
