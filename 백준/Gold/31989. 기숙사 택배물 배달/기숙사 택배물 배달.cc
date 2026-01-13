#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
ll n, m;
vector<ll> v;

ll f(vector<pair<ll, ll>> &seq) {

    if (seq.empty()) return 0;
    ll sum = 0, cur = n + 1;
    ll res = abs(v[seq.back().first] - v[n + 1]);

    for (auto &it : seq) sum += it.second;

    for (auto &it : seq) {
        ll dist = abs(v[cur] - v[it.first]);
        res += dist * (sum + 1);
        sum -= it.second;
        cur = it.first;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    v.resize(2 * n + 2);
    for (ll i = 1; i <= 2 * n + 1; i++) cin >> v[i];

    vector<pair<ll, ll>> left, right;

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;

        if (a < n + 1)
            left.push_back({a, b});
        else if (a > n + 1)
            right.push_back({a, b});
    }

    sort(left.begin(), left.end(), [](pair<ll, ll> &a, pair<ll, ll> &b) { return a.first > b.first; });
    sort(right.begin(), right.end());

    ll res = f(left) + f(right);

    cout << res;
    return 0;
}