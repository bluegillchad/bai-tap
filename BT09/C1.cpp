#include <iostream>
using namespace std;

int length(const char a[])
{
    int dem = 0;
    while (*(a + dem) != '\0') dem++;
    return dem;
}

char* revers(const char a[])
{
    int dai = length(a);
    char *b = new char [dai];
    for (int i = 0; i < dai; i++) *(b + dai - i - 1) = *(a + i);
    return b;
}

char* delete_char (const char *a, char c)
{
    int dem = 0;
    int dai = length(a);
    for (int i = 0; i < dai; i++)
    {
        if (*(a + i) == c) dem++;
    }
    char *b = new char [dai - dem];
    for (int i = 0, j = 0; i < dai; i++)
    {
        if (*(a + i) != c)
        {
            *(b + j) = *(a + i);
            j++;
        }
    }
    *(b + dai - dem) = '\0';
    return b;
}

char* pad_right(const char a[], int n)
{
    int dai = length(a);
    char *b = new char [n];
    for (int i = 0; i < n; i++)
    {
        if (i < dai) *(b + i) = *(a + i);
        else *(b + i) = ' ';
    }
    return b;
}

char* pad_left(const char a[], int n)
{
    int dai = length(a);
    char *b = new char [n];
    for (int i = 0; i < n; i++)
    {
        if (i < n - dai) *(b + i) = ' ';
        else *(b + i) = *(a + i - n + dai);
    }
    return b;
}

char* truncate(const char a[], int n)
{
    char *b = new char [n];
    for (int i = 0; i < n; i++) *(b + i) = *(a + i);
    *(b + n) = '\0';
    return b;
}

bool is_palindrome(char a[])
{
    int dai = length(a);
    for (int i = 0; i < dai / 2; i++)
    {
        if (*(a + i) != *(a + dai - i - 1)) return false;
    }
    return true;
}

char* trim_left(const char a[])
{
    int dai = length(a);
    int dem = 0;
    while (*(a + dem) == ' ') dem++;
    char *b = new char [dai - dem];
    for (int i = 0, j = 0; i < dai; i++)
    {
        if (*(a + i) != ' ')
        {
            *(b + j) = *(a + i);
            j++;
        }
    }
    *(b + dai - dem) = '\0';
    return b;
}

char* trim_right(const char a[])
{
    int dai = length(a);
    int dem = 0;
    while (*(a + dai - 1 - dem) == ' ') dem++;
    char *b = new char [dai - dem];
    for (int i = 0, j = 0; i < dai; i++)
    {
        if (*(a + i) != ' ')
        {
            *(b + j) = *(a + i);
            j++;
        }
    }
    *(b + dai - dem) = '\0';
    return b;
}

int main()
{
    char a[] = "abcdefghijkl";
    cout << revers(a) << endl;
    char b[] = "aabbbcc";
    cout << delete_char(b, 'b') << "abc" << endl;
    char c[] = "abc";
    cout << pad_right(c, 10) << "abc" << endl;
    char d[] = "abc";
    cout << pad_left(d, 10) << endl;
    char e[] = "abcdefghi";
    cout << truncate(e, 5) << endl;
    char f[] = "abcdedcba";
    char g[] = "abcdfcba";
    if ( is_palindrome(f) ) cout << "yes";
    else cout << "no";
    cout << endl;
    if ( is_palindrome(g) ) cout << "yes";
    else cout << "no";
    cout << endl;
    char h[] = "     abc";
    cout << trim_left(h) << endl;
    char i[] = "abc     ";
    cout << trim_right(i) << "abc";
    return 0;
}

