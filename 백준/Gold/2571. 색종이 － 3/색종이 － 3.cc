#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 101
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int f(int x, int y, vector<vector<int>> &acc) {

    int ret = 0;
    for (int i = x; i < MAX; i++) {
        for (int j = y; j < MAX; j++) {
            int width = i - x + 1, height = j - y + 1;
            int area = width * height;
            int acc_sum = acc[i][j] - acc[x - 1][j] - acc[i][y - 1] + acc[x - 1][y - 1];

            if (area == acc_sum) ret = max(ret, area);
        }
    }

    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v(MAX, vector<int>(MAX)), acc(MAX, vector<int>(MAX));

    while (n--) {
        int a, b;
        cin >> a >> b;
        for (int i = a; i < a + 10; i++) {
            for (int j = b; j < b + 10; j++) {
                v[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            acc[i][j] = acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1] + v[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            if (v[i][j] == 0) continue;
            res = max(res, f(i, j, acc));
        }
    }

    cout << res;
    return 0;
}