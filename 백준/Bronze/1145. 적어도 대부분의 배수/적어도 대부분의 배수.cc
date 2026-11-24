#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int lcm(int a, int b) { return a * b / gcd(a, b); }
int gcd(int a, int b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 5;
    vector<int> v = vector<int>(n);
    for (auto &a : v) cin >> a;

    int ans = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                int res = lcm(v[i], lcm(v[j], v[k]));
                ans = min(ans, res);
            }
        }
    }

    cout << ans;
    return 0;
}