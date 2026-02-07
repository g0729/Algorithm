#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int n;
vector<pair<int, int>> v;

int getArea(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return ((a.first * b.second + b.first * c.second + c.first * a.second) -
            (b.first * a.second + c.first * b.second + a.first * c.second));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, int>> v(3);

    for (auto &a : v) cin >> a.first >> a.second;

    int ret = getArea(v[0], v[1], v[2]);

    cout << (ret == 0 ? 0 : (ret > 0 ? 1 : -1));
    return 0;
}