#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

void bfs(int cur, vector<vector<int>> &edges, vector<bool> &isFlood) {
    queue<int> q;
    q.push(cur);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &next : edges[cur]) {
            if (!isFlood[next]) continue;

            q.push(next);
            isFlood[next] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> edges(n + 1, vector<int>());

    while (m--) {
        int a, b;
        cin >> a >> b;

        if (v[a] < v[b])
            edges[a].push_back(b);
        else
            edges[b].push_back(a);
    }

    vector<bool> isFlood(n + 1, true);
    int k;
    cin >> k;

    while (k--) {
        int a;
        cin >> a;
        isFlood[a] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (isFlood[i]) continue;

        bfs(i, edges, isFlood);
    }

    for (int i = 1; i <= n; i++) {
        if (isFlood[i]) {
            cout << "flood";
            return 0;
        }
    }

    cout << "no flood";
    return 0;
}