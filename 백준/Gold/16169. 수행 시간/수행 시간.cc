#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n;
vector<int> edges[101];
vector<int> in_degree(101);
vector<int> Class[101];
vector<int> v(101);

void get_in_degree() {
    for (int i = 1; i <= n; i++) {
        for (auto &a : edges[i]) {
            in_degree[a]++;
        }
    }
}

void topo_sort() {
    get_in_degree();
    queue<int> q;

    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res[cur] += v[cur];

        for (auto &next : edges[cur]) {
            res[next] = max(res[next], (next - cur) * (next - cur) + res[cur]);
            in_degree[next]--;

            if (in_degree[next] == 0) {
                q.push(next);
            }
        }
    }

    cout << *max_element(res.begin(), res.end());
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = b;
        Class[a].push_back(i);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < Class[i].size(); j++) {
            for (int k = 0; k < Class[i + 1].size(); k++) {
                edges[Class[i][j]].push_back(Class[i + 1][k]);
            }
        }
    }

    topo_sort();

    return 0;
}