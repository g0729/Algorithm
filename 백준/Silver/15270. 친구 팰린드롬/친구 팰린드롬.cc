#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m, res;
vector<pair<int, int>> v;
vector<bool> visited(21);
void dfs(int now, int cnt) {

    res = max(res, min(cnt + 1, n));
    for (int i = now; i < m; i++) {
        int a = v[i].first, b = v[i].second;

        if (!visited[a] && !visited[b]) {
            visited[a] = visited[b] = true;

            dfs(i + 1, cnt + 2);

            visited[a] = visited[b] = false;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    dfs(0, 0);

    cout << res;
    return 0;
}