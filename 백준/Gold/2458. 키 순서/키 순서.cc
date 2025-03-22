#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> v(n + 1, vector<bool>(n + 1));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a][b] = true;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            for (int k = 1; k < n + 1; k++)
                if (v[j][i] && v[i][k])
                    v[j][k] = true;
        }
    }

    int res = 0;
    for (int i = 1; i < n + 1; i++)
    {
        bool flag = true;
        for (int j = 1; j < n + 1; j++)
        {
            if (i == j)
                continue;
            if (!v[j][i] && !v[i][j])
            {
                flag = false;
                break;
            }
        }
        res += flag ? 1 : 0;
    }

    cout << res;

    return 0;
}