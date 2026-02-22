#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &a : v) cin >> a;
    vector<vector<bool>> visited(n, vector<bool>(m));

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;

            if (v[i][j] != '-') continue;

            res++;
            for (int k = 0; k < m; k++) {
                int next = j + k;
                if (next >= m || v[i][next] != '-') break;

                visited[i][next] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;

            if (v[i][j] != '|') continue;

            res++;
            for (int k = 0; k < n; k++) {
                int next = i + k;
                if (next >= n || v[next][j] != '|') break;

                visited[next][j] = true;
            }
        }
    }

    cout << res;
    return 0;
}