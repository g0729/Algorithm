#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int t = 1;; t++) {
        int n;
        cin >> n;

        if (n == 0) break;

        vector<vector<int>> dp(n, vector<int>(3, 1e9)), v(n, vector<int>(3));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) cin >> v[i][j];
        }
        dp[0][1] = v[0][1];
        dp[0][2] = v[0][1] + v[0][2];

        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][0];
            dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][2]), min(dp[i - 1][1], dp[i][0])) + v[i][1];
            dp[i][2] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i][1])) + v[i][2];
        }

        cout << t << ". " << dp[n - 1][1] << "\n";
    }
    return 0;
}