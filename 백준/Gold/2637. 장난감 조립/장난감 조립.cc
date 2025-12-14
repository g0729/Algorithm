#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 110
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n;
vector<int> edges[MAX];
vector<int> in_degree(MAX);
vector<vector<int>> v(MAX, vector<int>(MAX));
vector<int> res(MAX);
set<int> base;

void get_in_degree() {
    for (int i = 1; i <= n; i++) {
        for (auto &next : edges[i]) {
            in_degree[next]++;
        }
    }
}

void topo_sort() {
    get_in_degree();

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!in_degree[i]) {
            q.push(i);
            base.insert(i);
            v[i][i] = 1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &next : edges[cur]) {
            in_degree[next]--;

            if (!in_degree[next]) q.push(next);

            if (base.find(cur) == base.end()) {
                for (int i = 1; i <= n; i++) {

                    if (v[cur][i] == 0) continue;

                    if (base.find(i) == base.end()) {
                        for (int j = 1; j <= n; j++) {
                            if (v[i][j] == 0) continue;

                            v[cur][j] += v[i][j] * v[cur][i];
                        }
                        v[cur][i] = 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (v[n][i] == 0) continue;

        if (base.find(i) == base.end()) {
            for (int j = 1; j <= n; j++) {
                if (v[i][j] == 0) continue;

                v[n][j] += v[i][j] * v[n][i];
            }
            v[n][i] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!v[n][i]) continue;
        cout << i << " " << v[n][i] << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int m;
    cin >> m;

    while (m--) {
        int x, y, k;
        cin >> x >> y >> k;

        edges[y].push_back(x);
        v[x][y] = k;
    }

    topo_sort();
    return 0;
}