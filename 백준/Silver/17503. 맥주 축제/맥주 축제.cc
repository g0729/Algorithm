#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
ll n, m, k;
vector<pair<ll, ll>> v;

bool check(ll target)
{
    ll sum = 0, cnt = 0;
    for (ll i = 0; i < k; i++)
    {
        if (v[i].second <= target)
        {
            sum += v[i].first;
            cnt++;
        }
        if (cnt >= n)
            break;
    }
    if (cnt < n)
        return false;
    return sum >= m;
}

ll bin_search()
{
    ll lo = 0, hi = 1e12;

    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;

        if (!check(mid))
            lo = mid;
        else
            hi = mid;
    }

    return hi;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;

    for (ll i = 0; i < k; i++)
    {
        pair<ll, ll> a;
        cin >> a.first >> a.second;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), [](pair<ll, ll> &a, pair<ll, ll> &b)
         { return a.first > b.first; });

    ll res = bin_search();

    if (res == 1e12)
        cout << "-1";
    else
        cout << res;
    return 0;
}