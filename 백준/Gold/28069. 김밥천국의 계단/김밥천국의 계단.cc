#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 3000000
int arr[MAX];

void bfs()
{
    int n, m;
    cin >> n >> m;

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (arr[now + 1] == 0 && now + 1 <= n)
        {
            arr[now + 1] = arr[now] + 1;
            q.push(now + 1);
        }
        if (arr[now + now / 2] == 0 && now + now / 2 <= n)
        {
            arr[now + now / 2] = arr[now] + 1;
            q.push(now + now / 2);
        }
    }
    if (arr[n] <= m)
        cout << "minigimbob";
    else
        cout << "water";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bfs();
    return 0;
}