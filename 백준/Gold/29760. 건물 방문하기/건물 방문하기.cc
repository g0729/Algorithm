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

    int n, h, w;
    cin >> n >> h >> w;

    vector<pair<int, int>> v(h + 1, {1001, -1});

    int minFloor = 1001, maxFloor = -1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        v[a].first = min(v[a].first, b);
        v[a].second = max(v[a].second, b);

        minFloor = min(minFloor, a);
        maxFloor = max(maxFloor, a);
    }

    vector<vector<int>> dp(h + 1, vector<int>(2));

    dp[minFloor][0] = 2 * v[minFloor].second - v[minFloor].first - 1 + (minFloor - 1) * 100;
    dp[minFloor][1] = v[minFloor].second - 1 + (minFloor - 1) * 100;
    for (int i = minFloor + 1; i <= maxFloor; i++) {
        if (v[i].first == 1001) {
            dp[i][0] = dp[i - 1][0] + 100;
            dp[i][1] = dp[i - 1][1] + 100;
            v[i].first = v[i - 1].first;
            v[i].second = v[i - 1].second;
            continue;
        }

        int dist = v[i].second - v[i].first + 100;
        dp[i][0] = dist + min(abs(v[i - 1].first - v[i].second) + dp[i - 1][0],
                              abs(v[i - 1].second - v[i].second) + dp[i - 1][1]);
        dp[i][1] = dist + min(abs(v[i - 1].first - v[i].first) + dp[i - 1][0],
                              abs(v[i - 1].second - v[i].first) + dp[i - 1][1]);
    }

    cout << min(dp[maxFloor][0], dp[maxFloor][1]);
    return 0;
}