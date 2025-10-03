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

    vector<int> v(11);
    for (int i = 0; i <= 10; i++) cin >> v[i];

    int t;
    cin >> t;
    int res = 0;
    while (t--) {
        int n, b;
        double a;

        cin >> n >> a >> b;

        if (a >= 2.0 && b >= 17) res += v[n];
    }

    cout << res;
    return 0;
}