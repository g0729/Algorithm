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

    int n, l, m;
    cin >> n >> l >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++)
        cin >> v[i].first >> v[i].second;

    int res = 0;
    for (int i = 0; i < m; i++)
    {
        int x = v[i].first, y = v[i].second;

        for (int width = 1; width < (l / 2); width++)
        {
            int height = (l / 2) - width;

            for (int sx = x - width; sx <= x; sx++)
            {
                int sum = 1;
                for (int j = 0; j < m; j++)
                {
                    if (i == j)
                        continue;
                    if (sx <= v[j].first && v[j].first <= (sx + width) && y <= v[j].second && v[j].second <= (y + height))
                        sum++;
                }
                res = max(res, sum);
            }
        }
    }

    cout << res;
    return 0;
}