#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nMin, nMax;
    double nMean = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (i == 0)
        {
            nMin = tmp;
            nMax = tmp;
        }
        else
        {
            if (tmp < nMin) nMin = tmp;
            if (tmp > nMax) nMax = tmp;
        }
        nMean += tmp;
    }
    nMean /= n;
    cout << "Mean:" << nMean << endl;
    cout << "Max:" << nMax << endl;
    cout << "Min:" << nMin << endl;
    return 0;
}

