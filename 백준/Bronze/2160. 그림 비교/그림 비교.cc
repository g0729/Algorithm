#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
char MAP[50][5][7];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 7; k++)
            {
                cin >> MAP[i][j][k];
            }
        }
    }

    int res = 1e9;
    pair<int, int> resIdx;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = 0;
            for (int k = 0; k < 5; k++)
            {
                for (int p = 0; p < 7; p++)
                {
                    if (MAP[i][k][p] != MAP[j][k][p])
                    {
                        temp++;
                    }
                }
            }
            if (res > temp)
            {
                res = temp;
                resIdx = {i + 1, j + 1};
            }
        }
    }

    cout << resIdx.first << " " << resIdx.second;
    
    return 0;
}