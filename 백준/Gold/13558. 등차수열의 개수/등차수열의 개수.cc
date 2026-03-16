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
    vector<int> v(n);
    for (auto &a : v) cin >> a;

    vector<int> L(30005, 0), R(30005, 0);

    for (int i = 1; i < n; i++) R[v[i]]++;
    L[v[0]]++;

    ll res = 0;

    for (int j = 1; j < n - 1; j++) {
        R[v[j]]--;

        int max_d = min(v[j] - 1, 30000 - v[j]);

        for (int d = 1; d <= max_d; d++) {
            res += (ll)L[v[j] - d] * R[v[j] + d];
            res += (ll)L[v[j] + d] * R[v[j] - d];
        }

        res += (ll)L[v[j]] * R[v[j]];

        L[v[j]]++;
    }

    cout << res;

    return 0;
}