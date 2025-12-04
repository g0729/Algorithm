#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 50000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

map<vector<int>, int> ranks;
int n, k;

bool check(vector<int> &v) {

    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1] > v[i]) return false;
    }

    return true;
}

int bfs(vector<int> start) {
    queue<vector<int>> q;
    q.push(start);
    vector<bool> visited(MAX);
    visited[ranks[start]] = true;
    int res = 0;
    while (!q.empty()) {

        int size = q.size();
        while (size--) {
            vector<int> cur = q.front();
            q.pop();

            if (check(cur)) return res;

            for (int i = 0; i <= n - k; i++) {
                vector<int> temp = cur;

                for (int j = 0; j < k / 2; j++) {
                    swap(temp[i + j], temp[i + k - j - 1]);
                }

                if (visited[ranks[temp]]) continue;

                q.push(temp);
                visited[ranks[temp]] = true;
            }
        }

        res++;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(i);

    int rank = 1;
    do {
        ranks[v] = rank++;
    } while (next_permutation(v.begin(), v.end()));

    vector<int> start(n);
    for (auto &a : start) cin >> a;

    cout << bfs(start);
    return 0;
}