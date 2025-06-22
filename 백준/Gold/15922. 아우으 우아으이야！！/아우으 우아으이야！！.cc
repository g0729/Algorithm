#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (auto &a : v) cin >> a.first >> a.second;

    sort(v.begin(), v.end());

    if (n == 1) {
        cout << v[0].second - v[0].first;
        return 0;
    }

    int res = 0;

    int l = v[0].first, r = v[0].second;

    for (int i = 1; i < n; i++) {
        if (r < v[i].first) {
            res += r - l;
            l = v[i].first;
            r = v[i].second;
        } else {
            r = max(r, v[i].second);
        }
    }

    res += r - l;

    cout << res;
    return 0;
}