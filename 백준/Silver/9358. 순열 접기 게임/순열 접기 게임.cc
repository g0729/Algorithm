#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int test_case = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n), next(n);

        for (auto &a : v) cin >> a;

        while (n != 2) {
            for (int i = 0; i < (n + 1) / 2; i++) {
                next[i] = v[i] + v[n - i - 1];
            }
            v = next;
            n = (n + 1) / 2;
        }

        cout << "Case #" << test_case++ << ": ";
        if (v[0] > v[1])
            cout << "Alice";
        else
            cout << "Bob";
        cout << "\n";
    }
    return 0;
}