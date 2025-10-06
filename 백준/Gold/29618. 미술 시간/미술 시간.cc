#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

vector<int> parent(100010);

int find(int x) {
    if (parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}
bool isUnion(int x, int y) {
    x = find(x);
    y = find(y);

    return x == y;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    parent[x] = y;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> res(n + 10);
    for (int i = 1; i <= n + 5; i++) parent[i] = i;

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;

        int cur = find(a);

        while (cur <= b) {
            res[cur] = c;
            merge(cur, cur + 1);
            cur = find(cur);
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    return 0;
}