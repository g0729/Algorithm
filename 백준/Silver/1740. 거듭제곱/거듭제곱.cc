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

    ll n;
    cin >> n;
    ll res = 0;
    ll pow = 1;

    while (n) {
        res += (n & 1) * pow;
        n >>= 1;
        pow *= 3;
    }

    cout << res;
    return 0;
}