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
        int x;
        cin >> x;

        if (x == 0) {
            cout << "1\n2\n";
            continue;
        }
        cout << "2\n";
        for (int i = x;; i++) {
            if (((x * i) ^ (x * (i + 1))) == x) {
                cout << i << " " << i + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}