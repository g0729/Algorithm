#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void move(pair<int, int> &cur, int &dir, char c) {
    if (c == 'F') {
        cur.first = cur.first + dx[dir];
        cur.second = cur.second + dy[dir];

        ;

    } else if (c == 'R') {
        dir = (dir + 1) % 4;
    } else if (c == 'L') {
        dir = (dir - 1 + 4) % 4;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pair<int, int> cur;
    int n;
    string s;

    int x = 0, y = 0, nx = 0, ny = 0, dir = 0;
    cin >> n >> s;

    for (auto &c : s) {
        move(cur, dir, c);

        x = min(x, cur.first);
        y = min(y, cur.second);
        nx = max(nx, cur.first);
        ny = max(ny, cur.second);
    }

    int height = nx - x + 1, width = ny - y + 1;

    vector<vector<bool>> v = vector<vector<bool>>(height, vector<bool>(width, false));
    cur = {abs(x), abs(y)};
    dir = 0;

    v[cur.first][cur.second] = true;
    for (auto &c : s) {
        move(cur, dir, c);
        v[cur.first][cur.second] = true;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (v[i][j])
                cout << ".";
            else
                cout << "#";
        }
        cout << "\n";
    }
    return 0;
}