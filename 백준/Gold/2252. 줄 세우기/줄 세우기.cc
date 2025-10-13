#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m;
vector<int> edges[33000];
vector<int> in_degree(33000);

void get_in_degree() {
    for (int i = 1; i <= n; i++)
        for (auto next : edges[i]) in_degree[next]++;
}

void topo_sort() {
    queue<int> q;

    get_in_degree();
    for (int i = 1; i <= n; i++) {
        if (!in_degree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << "  ";

        for (auto next : edges[cur]) {
            in_degree[next]--;

            if (!in_degree[next]) q.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
    }

    topo_sort();
    return 0;
}