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
    vector<ll> v(n);

    for (auto &a : v) cin >> a;

    ll cur = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (cur % v[i] == 0) continue;
        cur = v[i] * (cur / v[i] + 1);
    }

    cout << cur;
    return 0;
}