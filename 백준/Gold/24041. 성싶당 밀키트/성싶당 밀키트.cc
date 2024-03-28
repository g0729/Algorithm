#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

ll n, g, k;
vector<pair<ll, ll>> v;
vector<pair<ll, ll>> v2;

bool check(ll tar)
{
    ll sum = 0;

    vector<ll> temp;
    for (ll i = 0; i < v.size(); i++)
    {
        ll a = max(1LL, tar - v[i].second) * v[i].first;
        sum += a;
        temp.push_back(a);
    }

    for (ll i = 0; i < v2.size(); i++)
    {
        sum += max(1LL, tar - v2[i].second) * v2[i].first;
    }

    sort(temp.begin(), temp.end(), greater<ll>());

    for (ll i = 0; i < k && i < temp.size(); i++)
    {
        sum -= temp[i];
    }

    return sum <= g;
}
ll bin_search()
{
    ll lo = 1;
    ll hi = 2e9+1;

    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }

    return lo;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> g >> k;

    for (ll i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (c == 0)
            v2.push_back({a, b});
        else
            v.push_back({a, b});
    }

    cout << bin_search();
    return 0;
}