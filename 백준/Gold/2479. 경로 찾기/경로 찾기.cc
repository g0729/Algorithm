#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1001
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, k;
vector<vector<int>> dist(MAX, vector<int>(MAX));
vector<bitset<30>> v;
int src, dst;

vector<int> bfs() {
    queue<int> q;
    vector<int> parent(n + 1, -1);
    parent[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == dst) break;

        for (int i = 1; i <= n; i++) {
            if (dist[cur][i] != 1) continue;

            if (parent[i] != -1) continue;

            parent[i] = cur;
            q.push(i);
        }
    }
    vector<int> res;
    if (parent[dst] == -1) return vector<int>();

    int cur = dst;

    while (cur != 0) {
        res.push_back(cur);
        cur = parent[cur];
    }

    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    v.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        v[i] = bitset<30>(s);
    }

    cin >> src >> dst;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            dist[i][j] = (v[i] ^ v[j]).count();
        }
    }

    vector<int> res = bfs();

    if (res.empty()) {
        cout << "-1";
        return 0;
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    return 0;
}