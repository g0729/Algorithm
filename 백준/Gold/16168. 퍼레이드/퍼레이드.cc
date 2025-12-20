#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 3001
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

vector<int> edges[MAX];
vector<bool> visited(MAX);
vector<int> degree(MAX);

void dfs(int curr) {
    visited[curr] = true;
    for (auto &next : edges[curr]) {
        if (!visited[next]) dfs(next);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        degree[a]++, degree[b]++;
    }

    dfs(1);
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            cout << "NO";
            return 0;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= v; i++) {
        if (degree[i] % 2) cnt++;
    }

    if (cnt == 0 || cnt == 2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}