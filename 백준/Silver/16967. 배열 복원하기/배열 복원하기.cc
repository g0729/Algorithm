#include <bits/stdc++.h>
using namespace std;
#define MAX 300
int mapA[MAX][MAX];
int mapB[2 * MAX][2 * MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, w, x, y;
    cin >> h >> w >> x >> y;

    for (int i = 0; i < h + x; i++)
    {
        for (int j = 0; j < w + y; j++)
        {
            cin >> mapB[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i >= x && j >= y)
            {
                mapA[i][j] = mapB[i][j] - mapA[i - x][j - y];
            }
            else
            {
                mapA[i][j] = mapB[i][j];
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << mapA[i][j] << " ";
        }
        cout << "\n";
    }
}