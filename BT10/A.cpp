#include <iostream>
using namespace std;

struct Point
{
    double x;
    double y;

    Point()
    {
        x = 0;
        y = 0;
    }

    Point(double x_, double y_)
    {
        x = x_;
        y = y_;
    }

    void print()
    {
        cout << '(' << x << ',' << y << ')' << endl;
    }

    void superprint()
    {
        cout << "Dia chi cua a: " << this << endl;
        cout << "Dia chi cua x: " << &x << endl;
        cout << "Dia chi cua y: " << &y << endl;
    }
};

struct mang
{
    int *a;

    mang()
    {
        a = new int [3];
        for (int i = 0 ; i < 3; i++) a[i] = 0;
    }

    ~mang()
    {
        delete [] a;
    }
};

struct superpoint
{
    Point a;

    superpoint()
    {
        Point b;
        a = b;
    }
};
void thamtri (const Point a)
{
    cout << "Dia chi tham tri: " << &a << endl;
}

void thamchieu (const Point &a)
{
    cout << "Dia chi tham chieu: " << &a << endl;
}

Point mid_point(const Point &a, const Point &b)
{
    Point c;
    c.x = ( a.x + b.x ) / 2;
    c.y = ( a.y + b.y ) / 2;
    return c;
}

int main()
{
    double x, y;
    cin >> x >> y;
    Point a(x,y);
    Point b(y,x);
    a.print();
    cout << "Dia chi cua a: " << &a << endl;
    thamtri(a);
    thamchieu(a);
    mid_point(a, b).print();
    a.superprint(); // dia chi cua a trung voi dia chi truong dau tien cua a

    mang c;
    mang d = c;
    cout << c.a << ' ' << d.a << endl;

    superpoint e;
    superpoint f = e;
    cout << &(e.a) << ' ' << &(f.a);
    return 0;
}
