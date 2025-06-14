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

    int n;
    cin >> n;
    vector<vector<int>> MAP(n + 1, vector<int>(n + 1));
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(3)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> MAP[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int cur = MAP[i][j];
            int prev = (cur + 2) % 3;
            if (!(cur != 0 && dp[i - 1][j][prev] == 0 && dp[i][j - 1][prev] == 0))
                dp[i][j][cur] = max(dp[i - 1][j][prev], dp[i][j - 1][prev]) + 1;
            for (int k = 0; k < 3; k++) {
                if (cur == k) continue;
                dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
            }
        }
    }

    cout << *max_element(dp[n][n].begin(), dp[n][n].end());
    return 0;
}