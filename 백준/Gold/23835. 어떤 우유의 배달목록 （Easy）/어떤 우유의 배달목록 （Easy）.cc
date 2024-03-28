#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1001
#define INF 987654321

vector<int> v[MAX];
bool visited[MAX];
int arr[MAX];
bool dfs(int now, int tar, int cnt)
{
    if (now == tar)
    {
        arr[now] += cnt;
        return true;
    }

    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i];
        if (visited[next])
            continue;
        visited[next] = true;
        bool temp = dfs(next, tar, cnt + 1);
        visited[next] = false;
        if (temp)
        {
            arr[now] += cnt;
            return true;
        }
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c;
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c;
            visited[b] = true;
            dfs(b, c, 0);
            memset(visited, false, sizeof(visited));
        }
        else
        {
            cin >> b;
            cout << arr[b] << "\n";
        }
    }

    return 0;
}