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

    vector<pair<int, int>> v(m);

    for (int i = 0; i < m; i++)
        cin >> v[i].first >> v[i].second;

    int idx = 0;

    vector<string> res(n, string(m, '.'));

    for (int i = 0; i < m; i++)
    {
        int sum = n - (v[i].first + v[i].second);

        if (sum < 0)
        {
            cout << "NO";
            return 0;
        }

        while (idx < n && sum--)
            res[idx++][i] = 'X';
    }

    if (idx != n)
    {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (res[j][i] == 'X')
                continue;
            if (v[i].first)
            {
                res[j][i] = '+';
                v[i].first--;
            }
            else
            {
                res[j][i] = '-';
            }
        }
    }

    cout << "YES\n";
    for (auto &s : res)
        cout << s << "\n";

    return 0;
}