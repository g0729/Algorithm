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

    ll n, d;
    cin >> n >> d;
    vector<ll> monsters, gears;

    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (a == 1) {
            monsters.push_back(b);
        } else if (a == 2) {
            gears.push_back(b);
        }
    }
    sort(monsters.begin(), monsters.end());
    sort(gears.begin(), gears.end());
    ll idx1 = 0, idx2 = 0;
    ll res = 0;
    while (true) {

        while (idx1 < monsters.size() && d > monsters[idx1]) {
            d += monsters[idx1];
            idx1++;
            res++;
        }

        if (idx1 == monsters.size()) {
            cout << n;
            return 0;
        }

        if (idx2 == gears.size()) {
            break;
        }

        d *= gears[idx2++];
        res++;
    }

    cout << res;
    return 0;
}