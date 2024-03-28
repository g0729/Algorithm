#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 1000001

vector<int> v[MAX];
int dp[MAX][2];
bool visited[MAX];
void dfs(int now)
{
    visited[now] = true;
    dp[now][0] = 1;

    for (int i = 0; i < v[now].size(); i++)
    {
        int child = v[now][i];
        if (visited[child])
            continue;
        dfs(child);
        dp[now][1] += dp[child][0];
        dp[now][0] += min(dp[child][0], dp[child][1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);
    cout<<min(dp[1][0],dp[1][1]);
    return 0;
}