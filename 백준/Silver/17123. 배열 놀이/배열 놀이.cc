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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> v[i][j];
            }
        }

        vector<int> rows(n + 1), columns(n + 1);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                rows[i] += v[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                columns[i] += v[j][i];
            }
        }

        while (m--) {
            int r1, r2, c1, c2, val;
            cin >> r1 >> c1 >> r2 >> c2 >> val;
            int height = r2 - r1 + 1, width = c2 - c1 + 1;

            for (int i = r1; i <= r2; i++) {
                rows[i] += width * val;
            }

            for (int i = c1; i <= c2; i++) {
                columns[i] += height * val;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << rows[i] << " ";
        }

        cout << "\n";

        for (int i = 1; i <= n; i++) {
            cout << columns[i] << " ";
        }

        cout << "\n";
    }
    return 0;
}