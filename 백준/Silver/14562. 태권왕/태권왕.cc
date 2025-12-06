#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 200
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int bfs(int val, int target) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(MAX, vector<bool>(MAX));
    q.push({val, target});
    visited[val][target] = true;

    int res = 0;
    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int cur = q.front().first;
            int opp = q.front().second;
            q.pop();
            if (cur == opp) return res;

            if ((cur * 2 < MAX && opp + 3 < MAX) && cur * 2 <= (opp + 3) && !visited[cur * 2][opp + 3]) {
                visited[cur * 2][opp + 3] = true;
                q.push({cur * 2, opp + 3});
            }

            if (cur + 1 < MAX && !visited[cur + 1][opp]) {
                visited[cur + 1][opp] = true;
                q.push({cur + 1, opp});
            }
        }
        res++;
    }

    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b) << "\n";
    }
    return 0;
}