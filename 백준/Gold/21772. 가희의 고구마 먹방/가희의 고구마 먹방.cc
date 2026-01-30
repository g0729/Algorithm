#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 101
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int R, C, T;
vector<string> MAP;
map<pair<int, int>, int> ma;
vector<int> states;
int res = 0;
void dfs(int cur, pair<int, int> p) {

    if (cur == T) {
        int cnt = 0;
        for (int i = 0; i < states.size(); i++) cnt += (states[i] ? 1 : 0);
        res = max(res, cnt);

        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (MAP[nx][ny] == '#') continue;

        if (MAP[nx][ny] == 'S') states[ma[{nx, ny}]]++;
        dfs(cur + 1, {nx, ny});
        if (MAP[nx][ny] == 'S') states[ma[{nx, ny}]]--;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> T;

    MAP.resize(R);
    for (auto &s : MAP) cin >> s;
    int idx = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (MAP[i][j] == 'S') ma.insert({{i, j}, idx++});
        }
    }

    states.resize(ma.size(), false);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (MAP[i][j] == 'G') dfs(0, {i, j});
        }
    }

    cout << res;
    return 0;
}