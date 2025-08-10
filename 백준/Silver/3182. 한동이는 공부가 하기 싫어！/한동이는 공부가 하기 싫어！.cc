#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;
vector<int> v;
int bfs(int start) {
    vector<bool> visited(n + 1);
    visited[start] = true;

    int cnt = 1;

    while (!visited[v[start]]) {
        start = v[start];
        visited[start] = true;
        cnt++;
    }

    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    int res_max = 0;
    int res_idx = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = bfs(i);

        if (cnt > res_max) {
            res_max = cnt;
            res_idx = i;
        }
    }

    cout << res_idx;
    return 0;
}