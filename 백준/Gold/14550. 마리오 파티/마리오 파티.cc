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

    while (true) {
        int n, s, t;
        cin >> n;

        if (n == 0) break;

        cin >> s >> t;

        vector<int> v(n + 2);
        for (int i = 1; i <= n; i++) cin >> v[i];

        vector<vector<int>> dp(n + s + 10, vector<int>(t + 1, -1e9));

        dp[0][0] = 0;
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= t; j++) {

                for (int k = max(i - s, 0); k < min(i, n + 1); k++) {
                    if (dp[k][j - 1] == (-1e9)) continue;

                    dp[i][j] = max(dp[k][j - 1] + v[i], dp[i][j]);
                }
            }
        }

        cout << *max_element(dp[n + 1].begin(), dp[n + 1].end()) << "\n";
    }
    return 0;
}