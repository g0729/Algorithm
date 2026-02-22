#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m;
vector<int> v;

int bfs() {
    queue<int> q;
    vector<int> visited(40000);
    for (int i = 0; i < n; i++) {
        q.push(v[i] + 20000);
        visited[v[i] + 20000] = 1;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            int next = cur + v[i];

            if (next < 0 || next >= 40000) break;
            if (visited[next] != 0) continue;

            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }

    return visited[m + 20000] == 0 ? -1 : visited[m + 20000];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    v.resize(n);
    for (auto &a : v) cin >> a;

    if (m == 0) {
        cout << "0";
        return 0;
    }
    cout << bfs();
    return 0;
}