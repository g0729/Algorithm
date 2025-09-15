#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m;
string s;
bool check(vector<string> &MAP, int x, int y, int dir) {
    int idx = 0;
    pair<int, int> cur = {x, y};
    for (int i = 0; i < s.length(); i++) {
        if (MAP[cur.first][cur.second] == s[idx]) {
            idx++;
            cur.first = cur.first + dx[dir];
            cur.second = cur.second + dy[dir];
        } else {
            return false;
        }

        if (idx == s.length()) return true;

        if (cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= m) return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    cin >> n >> m;
    vector<string> MAP(n);

    for (auto &a : MAP) cin >> a;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (MAP[i][j] == s[0]) {
                for (int k = 0; k < 8; k++) {
                    if (check(MAP, i, j, k)) {
                        cout << "1";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "0";
    return 0;
}