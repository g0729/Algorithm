#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 1; i <= n; i++) {
        v[i - 1].first = i;
        cin >> v[i - 1].second;
    }

    int res_1 = 0;

    for (int i = 1; i < v.size(); i++) {
        res_1 = max(res_1, abs(v[i].second - v[i - 1].second));
    }

    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; });

    int res_2 = 0;

    for (int i = 1; i < v.size(); i++) {
        res_2 = max(res_2, abs(v[i].first - v[i - 1].first));
    }

    cout << res_1 << "/1\n" << "1/" << res_2;

    return 0;
}