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

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> res(n + 1);
    for (auto &a : v) cin >> a;
    vector<int> pos(n + 1);

    for (int i = 0; i < n; i++) {
        pos[v[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int num = i + 1;
        int cur = v[i];
        int dist = pos[num] - i;
        res[num] += dist;
        res[cur] += dist;

        swap(v[i], v[pos[num]]);
        pos[cur] = pos[num];
        pos[num] = i;
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}