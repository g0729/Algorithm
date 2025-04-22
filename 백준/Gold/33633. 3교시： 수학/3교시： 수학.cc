#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;

    queue<ll> q;
    q.push(1);

    set<ll> visited;
    for (ll i = 0; i < n - 1; i++)
    {
        ll size = q.size();
        while (size--)
        {
            ll cur = q.front();
            q.pop();

            q.push(cur * 2);

            if ((cur - 1) % 3 == 0 && (cur - 1) / 3 > 1 && ((cur - 1) / 3) % 2 == 1)
            {
                q.push((cur - 1) / 3);
            }
        }
    }

    vector<ll> ans;
    while (!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";

    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}