#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int n;
vector<pair<int, int>> v;
vector<bool> selected;
int res = 1e9;
void dfs(int cnt)
{
    if (cnt == n)
    {
        int sour = 1;
        int bitter = 0;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                sour *= v[i].first;
                bitter += v[i].second;
                flag = true;
            }
        }
        if (flag)
        {
            res = min(res, abs(sour - bitter));
        }
        return;
    }
    selected[cnt] = true;
    dfs(cnt + 1);
    selected[cnt] = false;
    dfs(cnt + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    selected = vector<bool>(n);
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