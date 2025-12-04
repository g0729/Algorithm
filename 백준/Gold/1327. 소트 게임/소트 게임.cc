#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 50000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

map<vector<int>, int> dist;
int n, k;

int bfs(vector<int> start) {

    if (is_sorted(start.begin(), start.end())) return 0;

    queue<vector<int>> q;
    q.push(start);
    dist[start] = 1;

    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();

        if (is_sorted(cur.begin(), cur.end())) return dist[cur] - 1;

        for (int i = 0; i <= n - k; i++) {
            vector<int> next = cur;

            reverse(next.begin() + i, next.begin() + i + k);

            if (dist.find(next) == dist.end()) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    vector<int> start(n);

    for (auto &a : start) cin >> a;

    cout << bfs(start);
    return 0;
}