#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1001
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

vector<ll> parent(MAX);

ll find(ll x) {
    if (parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

bool isUnion(ll x, ll y) {
    x = find(x);
    y = find(y);

    return x == y;
}
void merge(ll x, ll y) {
    x = find(x);
    y = find(y);

    parent[y] = x;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    for (ll i = 1; i <= n; i++) parent[i] = i;

    vector<pair<ll, ll>> polls(n);
    vector<pair<pair<ll, ll>, double>> dist;
    for (auto &a : polls) cin >> a.first >> a.second;

    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;

        merge(u, v);
    }

    auto distance = [](const pair<ll, ll> &a, const pair<ll, ll> &b) -> double {
        return sqrt((a.first - b.first) * (a.first - b.first) +
                    (a.second - b.second) * (a.second - b.second));
    };

    for (ll i = 0; i < n - 1; i++) {
        for (ll j = i + 1; j < n; j++) {
            dist.push_back({{i + 1, j + 1}, distance(polls[i], polls[j])});
        }
    }

    sort(dist.begin(), dist.end(),
         [](pair<pair<ll, ll>, double> &a, pair<pair<ll, ll>, double> &b) {
             return a.second < b.second;
         });

    double res = 0.0;

    for (auto &[uv, cost] : dist) {
        auto &[u, v] = uv;

        if (isUnion(u, v)) continue;

        merge(u, v);

        res += cost;
    }

    cout << fixed;
    cout.precision(2);
    cout << res;
    return 0;
}