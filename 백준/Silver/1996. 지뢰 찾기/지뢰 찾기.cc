#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<string> ans(n, string(n, '*'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            if (v[i][j] != '.')
                continue;
            for (int k = 0; k < 8; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x < 0 || x >= n || y < 0 || y >= n)
                    continue;
                if (v[x][y] != '.')
                    sum += v[x][y] - '0';
            }

            if (sum >= 10)
                ans[i][j] = 'M';
            else
                ans[i][j] = sum + '0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}