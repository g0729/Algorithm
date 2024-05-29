#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

ll distance(ll &x, ll &y)
{
    return x * x + y * y;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll pi;
        cin >> pi;

        ll furthest = 0;
        for (ll i = 0; i < pi; i++)
        {
            ll a, b;
            cin >> a >> b;
            furthest = max(furthest, distance(a, b));
        }
        v.push_back(furthest);
    }

    sort(v.begin(), v.end());

    cout << v[k - 1] << ".00";

    return 0;
}