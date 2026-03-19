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

    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &a : v) {
        cin >> a;
        sum += a;
    }

    int res = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++) {
        res += v[i] * (sum - v[i]);
        sum -= v[i];
    }

    cout << res;
    return 0;
}