#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
vector<vector<bool>> visited;
vector<vector<int>> edges;
vector<pair<char, int>> states;

bool bfs(int n) {
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int cur = q.front().first, money = q.front().second;

        if (cur == n) return true;
        q.pop();

        for (auto &next : edges[cur]) {
            if (states[next].first == 'E' && !visited[next][money]) {
                q.push({next, money});
                visited[next][money] = true;
            } else if (states[next].first == 'L' && !visited[next][max(money, states[next].second)]) {
                q.push({next, max(money, states[next].second)});
                visited[next][max(money, states[next].second)] = true;
            } else if (states[next].first == 'T' && money >= states[next].second &&
                       !visited[next][money - states[next].second]) {
                q.push({next, money - states[next].second});
                visited[next][states[next].second] = true;
            }
        }
    }

    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        visited = vector<vector<bool>>(n + 1, vector<bool>(501));
        edges = vector<vector<int>>(n + 1, vector<int>());
        states = vector<pair<char, int>>(n + 1);
        for (int i = 1; i <= n; i++) {
            char c;
            int cost;
            cin >> c >> cost;
            states[i] = {c, cost};

            int a;
            while (cin >> a && a != 0) {
                edges[i].push_back(a);
            }
        }

        edges[0].push_back(1);

        cout << (bfs(n) ? "Yes" : "No") << "\n";
    }
    return 0;
}