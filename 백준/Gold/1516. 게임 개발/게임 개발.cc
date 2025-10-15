#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n;
vector<int> in_degree(501);
vector<int> edges[501];
vector<int> costs(501);

void get_in_degree() {

    for (int i = 1; i <= n; i++) {
        for (auto next : edges[i]) in_degree[next]++;
    }
}

void topo_sort() {

    get_in_degree();
    vector<int> dp(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in_degree[i]) {
            q.push(i);
            dp[i] = costs[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : edges[cur]) {
            in_degree[next]--;
            dp[next] = max(dp[next], dp[cur] + costs[next]);

            if (!in_degree[next]) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> costs[i];
        int a;
        while (cin >> a && a != -1) {
            edges[a].push_back(i);
        }
    }

    topo_sort();
    return 0;
}