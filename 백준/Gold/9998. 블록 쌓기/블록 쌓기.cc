#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int n;
vector<ll> Y;
vector<ll> D;

ll costFuncton(ll target) {
    ll ret = 0;
    int center = n / 2;

    for (int i = 0; i < n; i++) {
        ll height = target + abs(i - center);

        ret += abs(height - Y[i]);
        ret += abs(height - D[i]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    Y.resize(n);
    D.resize(n);

    for (auto &a : Y) cin >> a;
    for (auto &a : D) cin >> a;

    ll lo = 0, hi = 2e12;

    while (lo + 3 <= hi) {
        ll p = (lo * 2 + hi) / 3;
        ll q = (lo + hi * 2) / 3;

        if (costFuncton(p) <= costFuncton(q))
            hi = q;
        else
            lo = p;
    }

    ll ans = -1;

    for (ll i = lo; i <= hi; i++) {
        ll temp = costFuncton(i);
        if (ans == -1 || temp < ans) ans = temp;
    }

    cout << ans << "\n";
    return 0;
}