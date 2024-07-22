#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        ll temp = gcd(a, b);
        v.push_back({a / temp, b / temp});
    }

    ll demo = v[0].second;

    for (ll i = 1; i < n; i++)
        demo = demo * v[i].second / gcd(demo, v[i].second);

    ll nume = v[0].first * (demo / v[0].second);

    for (ll i = 1; i < n; i++)
        nume = gcd(nume, v[i].first * (demo / v[i].second));

    cout << nume << " " << demo;
    return 0;
}