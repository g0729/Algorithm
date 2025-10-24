#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int res = 1e9;
int n, m;
vector<int> v;
void dfs(int left, int right, int idx, int cnt) {

    if (idx == m) {
        res = min(res, cnt);
        return;
    }
    int cur = v[idx];

    if (left <= cur && cur <= right) {
        dfs(cur, right, idx + 1, cnt + cur - left);
        dfs(left, cur, idx + 1, cnt + right - cur);

    } else if (cur < left) {
        dfs(cur, right, idx + 1, cnt + left - cur);
    } else if (right < cur) {
        dfs(left, cur, idx + 1, cnt + cur - right);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int left, right;
    cin >> n;
    cin >> left >> right;
    cin >> m;
    v.resize(m);
    for (auto &a : v) cin >> a;

    dfs(left, right, 0, 0);

    cout << res;
    return 0;
}