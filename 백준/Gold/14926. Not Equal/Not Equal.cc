#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int n;
bool isUsed[501][501];
vector<int> path;
void f(int u) {
    for (int v = 1; v <= n; v++) {
        if ((u != v) && !isUsed[u][v]) {
            isUsed[u][v] = isUsed[v][u] = true;
            f(v);
        }
    }

    path.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    f(1);

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << "a" << path[i] << " ";
    }

    return 0;
}