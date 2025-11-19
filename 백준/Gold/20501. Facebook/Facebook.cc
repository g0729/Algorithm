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

    int n;
    cin >> n;
    vector<bitset<2000>> v(n + 1);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        v[i] = bitset<2000>(s);
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (v[a] & v[b]).count() << "\n";
    }
    return 0;
}