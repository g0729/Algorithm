#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
ll n;

ll bfs(ll idx, vector<bool> &visited) {
    queue<ll> q;
    q.push(idx);
    visited[idx] = true;

    ll size = 1;

    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        for (ll i = 0; i < 2; i++) {
            ll nx = cur + dx[i];

            if (nx >= n)
                nx = 0;
            else if (nx < 0)
                nx = n - 1;

            if (visited[nx]) continue;

            size++;
            visited[nx] = true;
            q.push(nx);
        }
    }

    return size;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<bool> visited(n);
    vector<ll> v(n);

    ll res = 0;
    for (auto &a : v) cin >> a;

    for (ll i = 0; i < n; i++) {
        if (v[i]) visited[i] = true;
        res += v[i];
    }

    for (ll i = 0; i < n; i++) {
        if (visited[i]) continue;

        ll size = bfs(i, visited);

        res += (size + 1) / 2;
    }

    cout << res;
    return 0;
}