#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> v(n + 2);
    vector<ll> acc(n + 2);
    ll left = 0, right = n + 1;

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        v[a] = b;
    }

    for (ll i = 1; i <= n + 1; i++) {
        acc[i] = acc[i - 1] + v[i];
    }

    for (ll i = 0; i < q; i++) {
        ll a;
        cin >> a;
        ll left_acc = acc[a] - acc[left], right_acc = acc[right] - acc[a];
        if (a >= right || a <= left) {
            cout << "0\n";
            continue;
        }
        if (left_acc > right_acc) {
            cout << right_acc;
            right = a;
        } else if (left_acc < right_acc) {
            cout << left_acc;
            left = a;
        } else if (left_acc == right_acc) {
            cout << left_acc;
            if (a <= ((n + 1) / 2))
                left = a;
            else
                right = a;
        }
        cout << "\n";
    }

    return 0;
}