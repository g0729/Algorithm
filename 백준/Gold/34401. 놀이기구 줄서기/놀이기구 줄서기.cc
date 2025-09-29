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

    int n, p, k;
    cin >> n >> p >> k;

    vector<pair<int, int>> v(n);
    queue<int> q[6];
    for (auto &a : v) cin >> a.first >> a.second;

    sort(v.begin(), v.end());

    int cur_time = 0;
    int idx = 0;
    ll res = 0;
    while (true) {

        while (idx < n && v[idx].first <= cur_time) {
            q[v[idx].second].push(v[idx].first);
            idx++;
        }

        int count = 0;

        while (true) {
            int idx = 0, time = 1e9;
            for (int i = 1; i <= k - count; i++) {
                if (!q[i].empty() && q[i].front() < time) {
                    idx = i;
                    time = q[i].front();
                }
            }

            if (idx == 0) break;
            res += cur_time - q[idx].front();
            count += idx;
            q[idx].pop();
        }

        bool flag = true;
        if (idx == n) {
            for (int i = 1; i <= 5; i++) {
                if (q[i].size() != 0) {
                    flag = false;
                    break;
                }
            }

            if (flag) break;
        }

        cur_time += p;
    }

    cout << res;

    return 0;
}