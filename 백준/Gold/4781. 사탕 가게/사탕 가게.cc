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

    while (true) {
        ll n;
        double m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;
        ll M = m * 100 + 0.5;

        vector<pair<ll, ll>> v(n);

        for (ll i = 0; i < n; i++) {
            ll a;
            double b;
            cin >> a >> b;
            ll B = b * 100 + 0.5;

            v[i] = {a, B};
        }

        vector<vector<ll>> dp(n + 1, vector<ll>(M + 1));

        for (ll i = 1; i <= n; i++) {
            ll val = v[i - 1].first;
            ll weight = v[i - 1].second;

            for (ll j = 1; j <= M; j++) {

                if (weight <= j) {
                    dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - weight] + val, dp[i][j - weight] + val));
                } else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        cout << dp[n][M] << "\n";
    }
    return 0;
}