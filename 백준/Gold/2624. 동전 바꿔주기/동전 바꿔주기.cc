#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, k;
    cin >> t >> k;

    vector<vector<int>> dp(k + 1, vector<int>(t + 1));
    vector<pair<int, int>> v(k);
    dp[0][0] = 1;
    for (auto &a : v) cin >> a.first >> a.second;

    for (int i = 1; i <= k; i++) {
        int val = v[i - 1].first, num = v[i - 1].second;

        for (int j = 0; j <= t; j++) {
            if (dp[i - 1][j]) {

                for (int k = j; k <= t && (k - j) / val <= num; k += val) {
                    dp[i][k] += dp[i - 1][j];
                }
            }
        }
    }

    cout << dp[k][t];
    return 0;
}