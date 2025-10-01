#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

ll pow(ll base, ll power) {
    if (power == 0) return 1;

    ll temp = pow(base, power / 2);
    ll ans = temp * temp % MOD;

    if (power % 2) return (ans * base) % MOD;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, n;
    cin >> a >> b >> n;

    ll base = ((ll)1 << 31);

    cout << pow(base, n - 1);
    return 0;
}