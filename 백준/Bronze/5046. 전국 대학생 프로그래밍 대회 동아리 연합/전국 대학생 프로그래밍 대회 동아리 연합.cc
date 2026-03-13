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

    int n, b, h, w;
    cin >> n >> b >> h >> w;
    int res = 1e9;
    for (int i = 0; i < h; i++) {
        int p;
        cin >> p;

        for (int j = 0; j < w; j++) {
            int a;
            cin >> a;
            if (a >= n && n * p <= b) {
                res = min(n * p, res);
            }
        }
    }

    if (res == 1e9)
        cout << "stay home";
    else
        cout << res;
    return 0;
}