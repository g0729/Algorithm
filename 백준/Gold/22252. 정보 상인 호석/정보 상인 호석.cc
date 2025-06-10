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

    ll q;
    cin >> q;
    map<string, priority_queue<ll>> ma;

    ll res = 0;
    while (q--) {
        ll op, k;
        string name;
        cin >> op >> name >> k;

        if (op == 1) {
            while (k--) {
                ll a;
                cin >> a;
                ma[name].push(a);
            }
        } else if (op == 2) {
            while (!ma[name].empty() && k--) {
                res += ma[name].top();
                ma[name].pop();
            }
        }
    }

    cout << res;
    return 0;
}