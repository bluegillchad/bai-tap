#include <iostream>
using namespace std;


int main() {
    int w, h;
    cin >> w >> h;
    bool checkRow[w];
    bool nextCheckRow[w];
    char grid;
    bool escape = false;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid;
            if (i == 0)
            {
                if (grid == 'Y') checkRow[j] = true;
                else checkRow[j] = false;
            }
            else
            {
                if (grid == 'R') nextCheckRow[j] = false;
                else
                {
                    if (j == 0)
                    {
                        if (checkRow[j] || checkRow[j+1]) nextCheckRow[j] = true;
                        else nextCheckRow[j] = false;
                    }
                    else if (j == w - 1)
                    {
                        if (checkRow[j] || checkRow[j-1]) nextCheckRow[j] = true;
                        else nextCheckRow[j] = false;
                    }
                    else
                    {
                        if (checkRow[j-1] || checkRow[j] || checkRow[j+1]) nextCheckRow[j] = true;
                        else nextCheckRow[j] = false;
                    }
                }
            }
        }
        if (i != 0)
        {
            for (int j = 0; j < w; j++)
            {
                checkRow[j] = nextCheckRow[j];
            }
        }
    }
    for (int j = 0; j < w; j++)
    {
        if (checkRow[j]) escape = true;
    }
    if (escape) cout << "YES";
    else cout << "NO";
    return 0;
}
