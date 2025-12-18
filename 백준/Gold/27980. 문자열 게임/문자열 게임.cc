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

    int n, m;
    string a, b;
    cin >> n >> m;
    cin >> a >> b;

    vector<int> cur(n), prev(n);

    for (int i = 0; i < n; i++) {
        if (a[i] == b[0]) prev[i] = 1;
    }

    for (int i = 1; i < m; i++) {
        cur[0] = prev[1] + (a[0] == b[i]);
        cur[n - 1] = prev[n - 2] + (a[n - 1] == b[i]);
        for (int j = 1; j < n - 1; j++) {
            cur[j] = max(prev[j - 1], prev[j + 1]) + (a[j] == b[i]);
        }

        prev = cur;
    }

    cout << *max_element(prev.begin(), prev.end());
    return 0;
}