#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int cnt[500][500][26];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> MAP;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        MAP.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x, y;
            x = i % k;
            y = j % k;

            cnt[x][y][MAP[i][j] - 'A']++;
        }
    }

    int res = 0;
    int total = (n / k) * (m / k);
    vector<string> v;
    for (int i = 0; i < k; i++)
    {
        string s;
        for (int j = 0; j < k; j++)
        {
            int idx = 0;
            int max_value = 0;
            for (int p = 0; p < 26; p++)
            {
                if (max_value < cnt[i][j][p])
                {
                    max_value = cnt[i][j][p];
                    idx = p;
                }
            }

            res += total - max_value;
            s.push_back('A' + idx);
        }
        v.push_back(s);
    }

    cout << res << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m / k; j++)
        {
            cout << v[i % k];
        }
        cout << "\n";
    }

    return 0;
}