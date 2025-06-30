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

    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    vector<pair<int, int>> v(2 * n);
    for (auto &a : v) cin >> a.first >> a.second;

    dp[1][v[0].first] = v[0].second;
    dp[1][v[1].first] = max(dp[1][v[1].first], v[1].second);

    for (int i = 2; i <= n; i++) {

        int weight = v[2 * (i - 1)].first;
        int val = v[2 * (i - 1)].second;

        for (int j = 1; j <= k; j++)
            if (weight <= j && dp[i - 1][j - weight] != 0) dp[i][j] = max(dp[i - 1][j - weight] + val, dp[i][j]);

        weight = v[2 * (i - 1) + 1].first;
        val = v[2 * (i - 1) + 1].second;

        for (int j = 1; j <= k; j++)
            if (weight <= j && dp[i - 1][j - weight] != 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - weight] + val);
    }

    cout << *max_element(dp[n].begin(), dp[n].end());
    return 0;
}