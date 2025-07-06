#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, q;
    cin >> n >> q;
    vector<pair<pair<ll, ll>, ll>> v;

    for (ll i = 1; i <= n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, i});
    }

    sort(v.begin(), v.end());

    ll idx = 1;
    ll r = -1;
    vector<ll> parent(n + 1);

    for (auto &[p, i] : v) {
        if (r < p.first) {
            parent[i] = ++idx;
            r = p.second;
        } else {
            parent[i] = idx;
            r = max(r, p.second);
        }
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;

        if (parent[a] == parent[b])
            cout << "1";
        else
            cout << "0";

        cout << "\n";
    }
    return 0;
}