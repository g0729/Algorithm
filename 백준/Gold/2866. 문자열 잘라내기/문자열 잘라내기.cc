#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c;
bool check(int target, vector<string> &v) {

    set<string> se;

    for (int j = 0; j < c; j++) {
        string temp;
        for (int k = target; k < r; k++) {
            temp.push_back(v[k][j]);
        }
        if (se.find(temp) != se.end()) {
            return false;
        } else {
            se.insert(temp);
        }
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    vector<string> v(r);

    for (auto &a : v) cin >> a;

    int lo = 0, hi = r;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if (check(mid, v))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo;
    return 0;
}