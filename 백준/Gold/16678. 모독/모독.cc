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

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &a : v) cin >> a;

    sort(v.begin(), v.end());

    ll idx = 1, res = 0;

    for (ll i = 0; i < v.size(); i++) {
        if (v[i] == idx) {
            idx++;
        } else if (v[i] < idx) {
            continue;
        } else if (v[i] > idx) {
            res += (v[i] - idx);
            idx++;
        }
    }

    cout << res;
    return 0;
}