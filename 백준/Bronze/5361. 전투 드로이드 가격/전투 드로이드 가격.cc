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

    vector<double> v = {350.34, 230.90, 190.55, 125.30, 180.90};

    int t;
    cin >> t;
    while (t--) {
        double res = 0.0;

        for (int i = 0; i < 5; i++) {
            int a;
            cin >> a;
            res += v[i] * a;
        }

        cout << fixed;
        cout.precision(2);
        cout << "$" << res << "\n";
    }

    return 0;
}