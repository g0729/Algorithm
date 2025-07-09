#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

ll f(ll target) {
    ll pos = 2;
    ll sum = (target + 1) / 2;
    while (pos <= target) {
        ll temp = target / (pos);
        if (temp % 2 == 0) {
            sum += (temp / 2) * pos;
        } else {
            sum += (temp - 1) / 2 * pos;
            sum += target - temp * pos + 1;
        }
        pos *= 2;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b;
    cin >> a >> b;

    cout << f(b) - f(a - 1);
    return 0;
}