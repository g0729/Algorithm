#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int f(int n) {
    int ret = 1;
    while (ret <= n) {
        ret <<= 1;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> res(n + 1);
    vector<bool> isUsed(n + 1);
    int target = f(n);
    for (int i = n; i >= 1; i--) {
        int temp = target;

        while (true) {
            int need = temp - i;

            if (need <= n && !isUsed[need]) {
                res[i] = need;
                isUsed[need] = true;
                break;
            }
            temp >>= 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << "\n";
    }
    return 0;
}