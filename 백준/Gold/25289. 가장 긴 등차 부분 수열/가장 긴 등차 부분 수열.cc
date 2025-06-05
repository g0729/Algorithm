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

    vector<int> v(n);

    for (auto &a : v) cin >> a;

    vector<vector<int>> dp(101, vector<int>(201));
    vector<int> cnt(101);
    int res = 1;
    for (int i = 0; i < n; i++) {

        int cur = v[i];
        cnt[cur]++;
        dp[cur][100] = cnt[cur];

        res = max(res, dp[cur][100]);
        for (int j = 0; j < 201; j++) {

            if (j == 100) continue;

            if (dp[cur][j] == 0) dp[cur][j] = 1;

            int diff = j - 100;
            int prev = cur - diff;

            if (prev < 1 || prev > 100) continue;

            dp[cur][j] = max(dp[cur][j], dp[prev][j] + 1);
            res = max(res, dp[cur][j]);
        }
    }

    cout << res;

    return 0;
}