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
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, 0});
    }

    sort(v.begin(), v.end());

    int res = 1;
    int cnt = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == 1) {
            cnt++;
        } else {
            res = max(res, cnt);
            cnt--;
        }
    }

    cout << res;

    return 0;
}