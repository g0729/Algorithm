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
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &a : v) cin >> a;

        ll res = 0;
        for (int i = 2; i < n; i++) {
            if (v[i] > 0) res += v[i];
        }

        res += max(0, max(v[0], v[0] + v[1]));

        cout << res << "\n";
    }
    return 0;
}