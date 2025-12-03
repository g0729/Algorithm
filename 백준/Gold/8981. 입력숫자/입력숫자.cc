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
    vector<int> res(n);
    for (auto &a : v) cin >> a;

    int from = 0;

    for (int i = 0; i < n; i++) {
        res[from] = v[i];

        from = (from + v[i]) % n;

        while (res[from] != 0 && i != (n - 1)) {
            from = (from + 1) % n;
        }
    }
    cout << n << "\n";
    for (auto &a : res) cout << a << " ";

    return 0;
}