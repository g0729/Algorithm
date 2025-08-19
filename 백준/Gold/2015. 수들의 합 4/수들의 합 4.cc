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
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n + 1);

    for (ll i = 1; i <= n; i++) cin >> v[i];
    vector<ll> acc_sum(n + 1);
    map<ll, ll> ma;
    ma[0] = 1;
    ll res = 0;
    for (ll i = 1; i <= n; i++) {
        acc_sum[i] = acc_sum[i - 1] + v[i];

        res += ma[acc_sum[i] - k];
        ma[acc_sum[i]]++;
    }

    cout << res;
    return 0;
}