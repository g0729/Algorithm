#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll val = (a.first * b.second + b.first * c.second + c.first * a.second) -
             (b.first * a.second + c.first * b.second + a.first * c.second);

    return val == 0 ? 0 : (val > 0 ? 1 : -1);
}

bool f(pair<ll, ll> a1, pair<ll, ll> a2, pair<ll, ll> b1, pair<ll, ll> b2) {
    ll l1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
    ll l2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);

    return l1 < 0 && l2 < 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pair<ll, ll> a1, a2, b1, b2;
    cin >> a1.first >> a1.second >> a2.first >> a2.second >> b1.first >> b1.second >> b2.first >> b2.second;
    cout << f(a1, a2, b1, b2);
    return 0;
}