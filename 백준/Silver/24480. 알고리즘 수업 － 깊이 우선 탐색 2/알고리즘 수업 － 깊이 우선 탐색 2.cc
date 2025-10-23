#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m, r;
vector<int> edges[100001];
vector<int> ans(100001);
int idx;
void dfs(int cur) {
    ans[cur] = ++idx;

    for (auto next : edges[cur]) {
        if (ans[next]) continue;
        dfs(next);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(edges[i].begin(), edges[i].end(), greater<int>());
    }

    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}