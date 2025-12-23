#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1010
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int n;
int adj[MAX][MAX];
int degree[MAX];
int lastIdx[MAX];
vector<int> paths;

void findCircuit(int u) {
    for (int &v = lastIdx[u]; v <= n; v++) {
        while (adj[u][v]) {
            adj[u][v]--, adj[v][u]--;
            findCircuit(v);
        }
    }
    paths.push_back(u);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if (i < j) {
                degree[i] += adj[i][j], degree[j] += adj[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2) {
            cout << -1;
            return 0;
        }
    }

    findCircuit(1);

    for (int i = paths.size() - 1; i >= 0; i--) {
        cout << paths[i] << " ";
    }
    return 0;
}