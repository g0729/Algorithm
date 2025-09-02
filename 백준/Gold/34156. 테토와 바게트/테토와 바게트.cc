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

    vector<pair<ll, ll>> v(n);

    for (auto &a : v) cin >> a.first >> a.second;

    sort(v.begin(), v.end(), [](pair<ll, ll> &a, pair<ll, ll> &b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    int res = 1;

    ll end = v[0].second;

    for (int i = 1; i < n; i++) {
        if (end > v[i].first)
            continue;
        else {
            res++;
            end = v[i].second;
        }
    }

    cout << res;
    return 0;
}