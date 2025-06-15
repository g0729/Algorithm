#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    int res = 0;

    for (auto &a : v) cin >> a;

    vector<int> cur(n);

    for (int i = 0; i < n; i++) {
        if (v[i] != cur[i]) {
            res++;
            for (int j = i; j < min(i + 3, n); j++) cur[j] ^= 1;
        }
    }

    cout << res;
    return 0;
}