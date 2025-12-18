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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m));
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[0]) dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = (a[j] == b[i] ? 1 : 0);
            if (j == 0) {
                dp[0][i] = dp[1][i - 1] + val;
            } else if (j == n - 1) {
                dp[n - 1][i] = dp[n - 2][i - 1] + val;
            } else {
                dp[j][i] = max(dp[j - 1][i - 1], dp[j + 1][i - 1]) + val;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, dp[i][m - 1]);

    cout << res;
    return 0;
}