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
    ll n, m, k;
    cin >> n >> m >> k;

    if (m <= 1)
    {
        cout << "YES";
        return 0;
    }
    vector<ll> s(n);

    for (ll i = 0; i < n; i++)
        cin >> s[i];

    vector<pair<ll, ll>> v(m);
    for (ll i = 0; i < m; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), [](pair<ll, ll> &a, pair<ll, ll> &b) -> bool
         { return a.first < b.first; });
    ll sum = 0, temp = 1e9;

    if (v.back().second == 1)
    {
        for (ll i = 0; i < v[0].first; i++)
            temp = min(temp, s[i]);
    }
    else
    {
        for (ll i = v.back().second - 1; i < n; i++)
            temp = min(temp, s[i]);
        for (ll i = 0; i < v[0].first; i++)
            temp = min(temp, s[i]);
    }
    sum += temp;

    for (ll i = 0; i < m - 1; i++)
    {
        ll left = v[i].second - 1, right = v[i + 1].first - 1;
        temp = 1e9;
        for (ll j = left; j <= right; j++)
            temp = min(temp, s[j]);

        sum += temp;
    }

    if (sum <= k)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}