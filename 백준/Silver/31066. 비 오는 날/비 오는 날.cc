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

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int res = 0;
        bool flag = false;
        for (int i = 0; i < 1000; i++) {
            a -= b * c;
            res++;
            if (a <= 0) {
                flag = true;
                cout << res << "\n";
                break;
            }
            a += 1;
            res++;
        }
        if (!flag) cout << "-1\n";
    }
    return 0;
}