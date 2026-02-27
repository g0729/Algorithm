#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int n, q;
vector<ll> v, drinks;
vector<int> parent;

int find(int x) {

    if (parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);

    parent[x] = y;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    v.resize(n + 1);
    parent.resize(n + 2);
    drinks.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n + 1; i++) {
        parent[i] = i;
    }
    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int i;
            ll x;
            cin >> i >> x;

            while (x) {
                i = find(i);

                if (i == n + 1) break;
                ll left = v[i] - drinks[i];

                if (x > left) {
                    x -= left;
                    drinks[i] = v[i];
                    merge(i, i + 1);
                } else {
                    drinks[i] += x;
                    x = 0;
                }
            }
        } else if (op == 2) {
            int x;
            cin >> x;
            cout << drinks[x] << "\n";
        }
    }

    return 0;
}