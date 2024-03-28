#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 15000000
#define INF 987654321
int n, a, b;
bool visited[MAX];
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int bfs()
{
    queue<int> q;
    visited[n] = true;
    q.push(n);

    int res = 0;
    while (!q.empty())
    {
        if (res >= 1e5)
            break;
        int size = q.size();
        while (size--)
        {
            int now = q.front();
            q.pop();

            if (now >= a && now <= b && isPrime(now))
                return res;

            int next;
            next = now / 2;
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
            next = now / 3;
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
            next = now + 1;
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
            next = now - 1;
            if (next >= 0 && !visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
        res++;
    }
    return -1;
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
        cin >> n >> a >> b;
        cout << bfs() << "\n";
        memset(visited, false, sizeof(visited));
    }
    return 0;
}