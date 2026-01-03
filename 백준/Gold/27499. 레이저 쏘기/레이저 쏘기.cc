#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    map<pair<ll, ll>, ll> ma;

    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        for (ll j = 0; j < k; j++) {
            ll nx, ny;

            if (j % 2 == 0) {
                nx = x + j * m;
            } else {
                nx = (j + 1) * m - x;
            }
            ll div = gcd(nx, y);
            nx = nx / div;
            ny = y / div;
            ma[{nx, ny}]++;
        }
    }
    ll res = 0;
    for (auto &it : ma) res = max(res, it.second);

    cout << res;

    return 0;
}