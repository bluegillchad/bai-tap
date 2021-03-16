#include <iostream>
using namespace std;

int length(char a[])
{
    int dem = 0;
    while (*(a + dem) != '\0') dem++;
    return dem;
}

char* revers(char a[])
{
    int dai = length(a);
    for (int i = 0; i < dai / 2; i++) swap(*(a + dai - 1 - i), *(a + i));
    return a;
}

char* delete_char (char a[], char c)
{
    int dem = 0;
    int dai = length(a);
    for (int i = 0; i < dai; i++)
    {
        if (*(a + i) == c)
        {
            for (int j = i; j < dai - 1; j++) *(a + j) = *(a + j + 1);
            *(a + dai - 1) = '\0';
            dai--;
            i--;
        }
    }
    return a;
}

char* pad_right(char a[], int n)
{
    int dai = length(a);
    for (int i = dai; i < n; i++)
    {
        *(a + i) = ' ';
    }
    return a;
}

char* pad_left(char a[], int n)
{
    int dai = length(a);
    while (dai < n)
    {
        for (int i = dai; i > 0; i--)
        {
            *(a + i) = *(a + i - 1);
        }
        dai++;
        *a = ' ';
    }
    return a;
}

char* truncate(char a[], int n)
{
    *(a + n) = '\0';
    return a;
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

char* trim_left(char a[])
{
    int dai = length(a);
    int i = 0;
    while (*(a + i) == ' ') i++;
    for (int j = 0; j < dai - i; j++) *(a + j) = *(a + i + j);
    *(a + dai - i) = '\0';
    return a;
}

char* trim_right(char a[])
{
    int i = 0;
    while (*(a + i) != ' ') i++;
    *(a + i) = '\0';
    return a;
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
