#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

vector<int> parent(100001);

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

    int n, m;
    cin >> n >> m;

    int res = 0;

    for (int i = 1; i <= n; i++) parent[i] = i;

    while (m--) {
        int a, b;
        cin >> a >> b;

        if (isUnion(a, b)) {
            res++;
            continue;
        }
        merge(a, b);
    }

    set<int> se;

    for (int i = 1; i <= n; i++) {
        se.insert(find(i));
    }

    res += (int)se.size() - 1;

    cout << res;
    return 0;
}