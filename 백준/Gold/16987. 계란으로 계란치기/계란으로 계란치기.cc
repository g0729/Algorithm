#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

vector<pair<int, int>> v;
int n, res;

void dfs(int cnt)
{
    if (cnt == n)
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i].first <= 0)
                temp++;
        }
        res = max(res, temp);
        return;
    }

    if (v[cnt].first <= 0)
        dfs(cnt + 1);
    else
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (cnt == i || v[i].first <= 0)
                continue;

            flag = true;
            v[i].first -= v[cnt].second;
            v[cnt].first -= v[i].second;
            dfs(cnt + 1);
            v[i].first += v[cnt].second;
            v[cnt].first += v[i].second;
        }

        if (!flag)
            dfs(n);
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
        pair<int, int> a;
        cin >> a.first >> a.second;
        v.push_back(a);
    }

    dfs(0);

    cout << res;
    return 0;
}