#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m;
vector<int> edges[1001];
vector<int> in_degree(1001);

void topo_sort() {
    for (int i = 1; i <= n; i++) {
        for (auto &next : edges[i]) in_degree[next]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in_degree[i]) q.push(i);
    }

    vector<int> res;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        res.push_back(cur);
        for (auto &next : edges[cur]) {
            in_degree[next]--;

            if (!in_degree[next]) q.push(next);
        }
    }

    if (res.size() != n) {
        cout << "0";
        return;
    }

    for (auto &a : res) cout << a << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    while (m--) {
        int num;
        cin >> num;
        vector<int> temp(num);
        for (auto &a : temp) cin >> a;

        for (int i = 0; i < num - 1; i++) {
            edges[temp[i]].push_back(temp[i + 1]);
        }
    }

    topo_sort();
    return 0;
}