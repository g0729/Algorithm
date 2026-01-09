#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000
#define INF 987654321
ll dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

ll lcm(ll a, ll b) {
    ll GCD = gcd(a, b);
    return a * b / GCD;
}

void solve(ll deno, ll nume) {

    ll cur = max(2LL, (deno + nume - 1) / nume);

    while (cur < MAX && deno) {

        ll LCM = lcm(cur, nume);
        ll aDeno = deno * (LCM / nume);
        ll bDeno = LCM / cur;

        if (aDeno < bDeno) {
            cur++;
            continue;
        }

        ll nextDeno = aDeno - bDeno;
        ll nextNume = LCM;
        ll GCD = gcd(nextDeno, nextNume);
        nextDeno = nextDeno / GCD, nextNume = nextNume / GCD;

        if (nextNume >= MAX) {
            cur++;
            continue;
        }

        cout << cur << " ";
        deno = nextDeno, nume = nextNume;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        ll a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;

        solve(a, b);

        cout << "\n";
    }
    return 0;
}