#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000001
#define INF 987654321
int n, k;
bool visited[MAX];
int bfs()
{
    queue<int> q;
    q.push(n);

    int lev = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int now = q.front();
            q.pop();
            if (now == k)
                return lev;
            if (!visited[now + 1])
            {
                visited[now + 1] = true;
                q.push(now + 1);
            }
            if (now * 2 < MAX && !visited[now * 2])
            {
                visited[now * 2] = true;
                q.push(now * 2);
            }
        }
        lev++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    cout << bfs();
    return 0;
}