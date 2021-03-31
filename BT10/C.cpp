#include <iostream>
using namespace std;

int length(const char a[])
{
    int dem = 0;
    while (*(a + dem) != '\0') dem++;
    return dem;
}

struct String
{
    int n;
    char *str;

    String(const char *a)
    {
        n = length(a);
        str = new char [n];
        for (int i = 0; i < n; i++) str[i] = a[i];
    }

    ~String()
    {
        delete [] str;
        n = 0;
    }

    void print()
    {
        for (int i = 0; i < n; i++) cout << str[i];
        cout << endl;
    }

    void append(const char* a)
    {
        n += length(a);
        char *tmp = new char [n];
        for (int i = 0; i < n; i++)
        {
            if (i < n - length(a)) tmp[i] = str[i];
            else tmp[i] = a[i - n + length(a)];
        }
        delete [] str;
        str = new char [n];
        for (int i = 0; i < n; i++) str[i] = tmp[i];
        delete [] tmp;
    }
};

int main()
{
    String a("abcd");
    a.print();
    cout << a.n << endl;
    a.append("efghij");
    a.print();
    cout << a.n << endl;
    return 0;
}
