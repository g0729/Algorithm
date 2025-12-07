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

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &a : v) cin >> a.first >> a.second;

    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    int right = -1;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].second <= right) continue;

        int width = (v[i].second - v[i].first);
        res += width * width;

        if (v[i].first < right) {
            int temp = right - v[i].first;
            res -= temp * temp;
        }

        right = v[i].second;
    }

    cout << res;
    return 0;
}