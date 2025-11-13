#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<pair<int, int>, int> ma[4];

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int temp = gcd(a, b);
        pair<int, int> slope = {a / temp, b / temp};
        if (a >= 0 & b > 0) {
            ma[0][slope]++;
        } else if (a < 0 && b >= 0) {
            ma[1][slope]++;
        } else if (a <= 0 && b < 0) {
            ma[2][slope]++;
        } else {
            ma[3][slope]++;
        }
    }
    int res = 0;

    for (int i = 0; i < 4; i++) {
        for (auto &it : ma[i]) {
            res = max(res, it.second);
        }
    }
    cout << res;
    return 0;
}