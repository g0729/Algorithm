#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

ll n, k;
vector<ll> v;

bool check(ll target) {
    ll sum = 0;

    for (auto &a : v) {
        sum += a / target;
    }

    return sum >= k;
}
ll bin_search() {
    ll lo = 0, hi = (1LL << 32) - 1;

    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }

    return lo;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    }

    cout << bin_search();
    return 0;
}