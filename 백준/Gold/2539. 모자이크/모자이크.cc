#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m, k, p;
vector<pair<int, int>> v;

bool check(int target) {
    int cur_x = 0;
    int total_used = 0;

    for (auto &a : v) {
        if (a.second <= cur_x) continue;

        cur_x = a.second + target - 1;
        total_used++;
    }

    return total_used <= k;
}

int bin_search() {
    int lo = 0, hi = 1e7;
    for (auto &a : v) lo = max(lo, a.first);
    lo--;
    while (lo + 1 < hi) {

        int mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }

    return hi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> p;

    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; });

    cout << bin_search();
    return 0;
}