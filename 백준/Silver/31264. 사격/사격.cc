#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

priority_queue<ll, vector<ll>, greater<ll>> pq;
ll n, m, a;

bool check(ll tar)
{
    priority_queue<ll, vector<ll>, greater<ll>> pq2 = pq;

    ll sum = 0;
    ll now = tar;

    ll before = 0;
    while (!pq2.empty() && pq2.top() <= now)
    {
        before = pq2.top();
        pq2.pop();
    }

    for (ll i = 0; i < m; i++)
    {
        sum += before;
        now += before;

        while (!pq2.empty() && pq2.top() <= now)
        {
            before = pq2.top();
            pq2.pop();
        }
    }

    return sum >= a;
}
ll binSearch()
{
    ll lo, hi;
    lo = 0;
    hi = 1e14;
    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }

    return hi;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a;

    for (ll i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        pq.push(b);
    }

    cout << binSearch();
    return 0;
}