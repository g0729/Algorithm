#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int n;
vector<int> v;
vector<int> cnt(4);
int res1 = -1e9, res2 = 1e9;

void dfs(int now, int sum)
{
    if (now == n)
    {
        res1 = max(res1, sum);
        res2 = min(res2, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (cnt[i])
        {
            cnt[i]--;
            if (i == 0)
                dfs(now + 1, sum + v[now]);
            else if (i == 1)
                dfs(now + 1, sum - v[now]);
            else if (i == 2)
                dfs(now + 1, sum * v[now]);
            else
                dfs(now + 1, sum / v[now]);
            cnt[i]++;
        }
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
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> cnt[i];
    }
    dfs(1, v[0]);
    cout << res1 << "\n"
         << res2;
    return 0;
}