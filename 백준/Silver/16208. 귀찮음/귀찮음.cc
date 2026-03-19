#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, sum = 0;
    cin >> n;
    vector<ll> v(n);
    for (auto &a : v) {
        cin >> a;
        sum += a;
    }

    ll res = 0;
    sort(v.begin(), v.end());
    for (ll i = 0; i < n - 1; i++) {
        res += v[i] * (sum - v[i]);
        sum -= v[i];
    }

    cout << res;
    return 0;
}