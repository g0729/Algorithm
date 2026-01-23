#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, Q, m;
vector<int> v;
vector<vector<int>> edges;
void bfs(int root) {
    queue<int> q;
    stack<int> st;
    q.push(root);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &next : edges[cur]) {
            q.push(next);
            st.push(next);
        }
    }

    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        Q--;

        cout << "1 " << cur << " " << v[cur] << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> Q;
    cout << n << " " << Q << "\n";
    v.resize(n + 1), edges.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> v[i];

    cin >> m;
    Q -= m;

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        cout << "2 " << a << "\n";
    }

    for (int i = 1; i <= n; i++) {
        if (i == v[i]) continue;
        edges[v[i]].push_back(i);
    }

    int root;
    for (int i = 1; i <= n; i++) {

        if (v[i] == i) {
            bfs(i);
            root = i;
        }
    }

    while (Q--) {
        cout << "1 " << root << " " << root << "\n";
    }
    return 0;
}