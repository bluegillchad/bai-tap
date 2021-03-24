#include <iostream>
using namespace std;

int length(const char a[])
{
    int dem = 0;
    while (*(a + dem) != '\0') dem++;
    return dem;
}

char* concat(const char* a, const char* b)
{
    int dai1 = length(a);
    int dai2 = length(b);
    char* c = new char [dai1 + dai2];
    for (int i = 0; i < dai1 + dai2; i++)
    {
        if (i < dai1)
        {
            *(c + i) = *(a + i);
        }
        else
        {
            *(c + i) = *(b + i - dai1);
        }
    }
    return c;
}
int main()
{
    char a[] = "abcd ";
    char b[] = "efgh";
    cout << concat(a, b);
}
