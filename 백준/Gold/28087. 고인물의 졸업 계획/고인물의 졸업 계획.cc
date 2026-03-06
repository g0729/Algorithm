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

    int n, m;
    cin >> n >> m;
    vector<int> v;
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;

        if (a > 2 * n) continue;

        if (a >= n) {
            cout << 1 << "\n" << i << "\n";
            return 0;
        }

        sum += a;
        v.push_back(i);

        if (sum >= n) {
            cout << v.size() << "\n";
            for (auto &a : v) cout << a << "\n";
            return 0;
        }
    }
    return 0;
}