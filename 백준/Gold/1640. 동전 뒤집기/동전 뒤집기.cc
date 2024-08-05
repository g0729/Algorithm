#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            v[i][j] = s[j] - '0';
        }
    }

    vector<vector<int>> c(v);

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < m; j++)
            temp += c[i][j];
        if (temp % 2)
        {
            cnt++;
            for (int j = 0; j < m; j++)
                c[i][j] = (c[i][j] + 1) % 2;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            temp += c[j][i];
        }
        if (temp % 2)
            cnt++;
    }

    int res = cnt;

    c = v;
    cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < m; j++)
            temp += c[i][j];
        if (temp % 2 == 0)
        {
            cnt++;
            for (int j = 0; j < m; j++)
                c[i][j] = (c[i][j] + 1) % 2;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            temp += c[j][i];
        }
        if (temp % 2)
            cnt++;
    }

    res = min(res, cnt);

    cout << res;
    return 0;
}