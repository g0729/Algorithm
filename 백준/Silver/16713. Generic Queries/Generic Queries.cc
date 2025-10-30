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

    int n, q;
    cin >> n >> q;
    vector<int> acc = {0};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        acc.push_back(acc.back() ^ a);
    }
    int res = 0;

    while (q--) {
        int l, r;
        cin >> l >> r;
        res ^= acc[r] ^ acc[l - 1];
    }

    cout << res;
    return 0;
}