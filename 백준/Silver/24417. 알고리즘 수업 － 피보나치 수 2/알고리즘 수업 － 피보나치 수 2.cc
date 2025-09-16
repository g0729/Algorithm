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
    ll n;
    cin >> n;
    ll a = 1, b = 1, c = 1;

    for (int i = 3; i <= n; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }

    cout << c << " " << (n - 2) % MOD;
    return 0;
}