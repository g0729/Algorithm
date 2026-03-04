#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n;
vector<string> MAP;
int cal(int x, int y) {

    int res = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        if (MAP[nx][ny] == '*') res++;
    }

    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    MAP.resize(n);
    for (auto &a : MAP) cin >> a;

    bool flag = false;

    vector<string> v(n);
    for (auto &a : v) cin >> a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 'x' && MAP[i][j] == '*') flag = true;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (flag && MAP[i][j] == '*')
                cout << "*";
            else if (v[i][j] == 'x') {
                cout << cal(i, j);
            } else {
                cout << ".";
            }
        }

        cout << "\n";
    }
    return 0;
}