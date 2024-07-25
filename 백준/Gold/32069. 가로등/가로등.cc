#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll n, l, k;
vector<ll> v;
ll dx[] = {1, -1};
void bfs()
{
    queue<ll> q;
    set<ll> visited;
    for (auto it : v)
    {
        q.push(it);
        visited.insert(it);
    }

    int distance = 0;
    int size;

    while (k)
    {
        size = q.size();
        while (size--)
        {
            ll now = q.front();
            q.pop();

            for (int i = 0; i < 2; i++)
            {
                ll next = now + dx[i];

                if (next < 0 || next > l)
                    continue;
                if (visited.find(next) != visited.end())
                    continue;
                q.push(next);
                visited.insert(next);
            }
            cout << distance << "\n";
            k--;
            if (k == 0)
                break;
        }
        distance++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> n >> k;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }

    bfs();

    return 0;
}