#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int dx[] = {1, 0};
int dy[] = {0, 1};
char MAP[50][50];
int n;
int res = 0;

void Check()
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;

        for (int j = 1; j < n; j++)
        {
            if (MAP[i][j - 1] == MAP[i][j])
                cnt++;
            else
                cnt = 1;
            res = max(res, cnt);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;

        for (int j = 1; j < n; j++)
        {
            if (MAP[j - 1][i] == MAP[j][i])
                cnt++;
            else
                cnt = 1;
            res = max(res, cnt);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x >= n || y >= n)
                    continue;
                swap(MAP[x][y], MAP[i][j]);
                Check();
                swap(MAP[x][y], MAP[i][j]);
            }
        }
    }
    cout << res;
    return 0;
}