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
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    vector<vector<pair<int, int>>> acc(n + 1, vector<pair<int, int>>(n + 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> v[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            acc[i][j].first = v[i][j] + acc[i - 1][j].first + acc[i][j - 1].first - acc[i - 1][j - 1].first;
            acc[i][j].second = acc[i - 1][j].second + acc[i][j - 1].second - acc[i - 1][j - 1].second + (v[i][j] ? 0 : 1);
        }
    int k;
    cin >> k;
    vector<int> v2(k), acc2(k + 1);
    for (int i = 0; i < k; i++)
        cin >> v2[i];
    sort(v2.begin(), v2.end(), greater<int>());
    for (int i = 1; i <= k; i++)
        acc2[i] = acc2[i - 1] + v2[i - 1];

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int p = 0; p <= (n - max(i, j)); p++)
            {
                int x = i + p, y = j + p;
                int sum, zero;
                sum = acc[x][y].first - acc[i - 1][y].first - acc[x][j - 1].first + acc[i - 1][j - 1].first;
                zero = acc[x][y].second - acc[i - 1][y].second - acc[x][j - 1].second + acc[i - 1][j - 1].second;
                if (zero > k)
                    break;
                res = max(res, sum + acc2[zero]);
            }

    cout << res;
    return 0;
}