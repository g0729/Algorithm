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

    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> visited(n);
    for (auto &a : v) cin >> a;

    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

    int res = 1, cur = v[0];
    visited[0] = true;

    for (int i = 1; i < n; i++) {
        if (cur > v[i]) {
            visited[i] = true, cur = v[i], res++;
        }
    }
    if (res != n) {

        for (int i = 0; i < n; i++)
            if (!visited[i]) {
                visited[i] = true, cur = v[i], res++;
                break;
            }

        for (int i = 1; i < n; i++) {
            if (cur > v[i] && !visited[i]) {
                visited[i] = true, cur = v[i], res++;
            }
        }
    }

    cout << res;
    return 0;
}