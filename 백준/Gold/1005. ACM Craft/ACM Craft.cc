#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int n, k, w;
vector<vector<int>> edges;
vector<int> d;
vector<int> in_degree;
void get_in_degree() {
    for (int i = 1; i <= n; i++) {
        for (auto next : edges[i]) in_degree[next]++;
    }
}

int topo_sort() {
    get_in_degree();

    queue<int> q;
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        if (!in_degree[i]) {
            q.push(i);
            dp[i] = d[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : edges[cur]) {
            in_degree[next]--;
            dp[next] = max(dp[next], dp[cur] + d[next]);

            if (!in_degree[next]) q.push(next);
        }
    }

    return dp[w];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;

        edges = vector<vector<int>>(n + 1);
        d = vector<int>(n + 1);
        in_degree = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) cin >> d[i];

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
        }
        cin >> w;

        cout << topo_sort() << "\n";
    }
    return 0;
}