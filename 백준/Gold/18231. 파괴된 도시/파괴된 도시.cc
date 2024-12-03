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
    vector<int> edges[2001];
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<bool> is_fired(n + 1);
    vector<bool> is_choosen(n + 1);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        is_fired[a] = true;
    }
    vector<int> res;

    for (int i = 1; i <= n; i++)
    {
        bool flag = true;

        if (!is_fired[i])
            continue;
        for (int j = 0; j < edges[i].size(); j++)
        {
            int next = edges[i][j];
            if (!is_fired[next])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            is_choosen[i] = true;
            for (int j = 0; j < edges[i].size(); j++)
                is_choosen[edges[i][j]] = true;
            res.push_back(i);
        }
    }

    if (res.size() == 0)
    {
        cout << "-1";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (is_fired[i] && !is_choosen[i])
        {
            cout << "-1";
            return 0;
        }
    }
    cout << res.size() << "\n";
    for (auto it : res)
        cout << it << " ";

    return 0;
}