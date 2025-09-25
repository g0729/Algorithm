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

    vector<pair<int, int>> v(m);
    for (auto &a : v) cin >> a.first >> a.second;

    int res = 0;
    for (int i = 0; i < (1 << m); i++) {
        int total_day = 0, total_page = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                total_day += v[j].first;
                total_page += v[j].second;
            }
        }

        if (total_day <= n) res = max(res, total_page);
    }

    cout << res;
    return 0;
}