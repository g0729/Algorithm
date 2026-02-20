#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v[i].first = a * 2, v[i].second = b * 2;
        }

        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        int res = 0;
        vector<bool> used(48, false);

        for (int i = 0; i < n; i++) {
            for (int j = v[i].first; j < v[i].second; j++) {
                if (!used[j]) {
                    used[j] = true;
                    res++;
                    break;
                }
            }
        }

        cout << "On day " << t << " Emma can attend as many as " << res << " parties.\n";
        t++;
    }
    return 0;
}