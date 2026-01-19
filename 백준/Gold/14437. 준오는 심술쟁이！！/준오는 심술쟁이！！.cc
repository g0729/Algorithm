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
    string s;
    cin >> n >> s;
    vector<vector<ll>> dp(s.length(), vector<ll>(n + 1));

    for (ll i = 0; i <= min(n, 25LL); i++) {
        dp[0][i] = 1;
    }

    for (ll i = 1; i < s.length(); i++) {
        for (ll j = 0; j <= 25; j++) {
            for (ll k = 0; k <= n; k++) {
                if ((k + j) > n) continue;
                dp[i][k + j] = (dp[i][k + j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    cout << dp[s.length() - 1][n];
    return 0;
}