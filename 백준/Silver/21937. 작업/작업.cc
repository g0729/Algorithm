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
    vector<vector<int>> v(n + 1, vector<int>());
    vector<bool> visited(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    int x;
    cin >> x;
    queue<int> q;
    q.push(x);
    visited[x] = true;

    int res = -1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res++;

        for (auto next : v[cur]) {
            if (visited[next]) continue;

            visited[next] = true;
            q.push(next);
        }
    }

    cout << res;
    return 0;
}