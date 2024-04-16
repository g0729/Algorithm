#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
vector<int> edge;
vector<int> visited;
vector<bool> finished;
int idx;
int cnt;
void dfs(int now)
{
    visited[now] = idx++;
    int next = edge[now];
    if (visited[next] == -1)
        dfs(next);
    else if (!finished[next])
        cnt += visited[now] - visited[next] + 1;

    finished[now] = true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        edge = vector<int>(n + 1);
        visited = vector<int>(n + 1, -1);
        finished = vector<bool>(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> edge[i];
        }

        for (int i = 1; i <= n; i++)
        {
            if (!finished[i])
                dfs(i);
        }
        cout << n - cnt << "\n";
        cnt = 0;
        idx = 0;
    }
    return 0;
}