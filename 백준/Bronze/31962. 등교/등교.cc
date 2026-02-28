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

    int res = -1;

    int n, x;
    cin >> n >> x;

    while (n--) {
        int a, b;
        cin >> a >> b;

        if ((a + b) <= x) {
            res = max(res, a);
        }
    }

    cout << res;
    return 0;
}