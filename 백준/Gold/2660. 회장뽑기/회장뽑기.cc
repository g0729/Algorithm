#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<int> v[51];
int score[51];
bool visited[51];
int bfs(int now)
{
    queue<int> q;
    q.push(now);
    visited[now] = true;

    int level = -1;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int now = q.front();
            q.pop();

            for (int i = 0; i < v[now].size(); i++)
            {
                int next = v[now][i];

                if (visited[next])
                    continue;

                visited[next] = true;
                q.push(next);
            }
        }
        level++;
    }

    return level;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        score[i] = bfs(i);
        ans = min(ans, score[i]);
        memset(visited, false, sizeof(visited));
    }

    vector<int> temp;
    for (int i = 1; i <= n; i++)
    {
        if (score[i] == ans)
            temp.push_back(i);
    }

    cout << ans << " " << temp.size() << "\n";

    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }

    return 0;
}