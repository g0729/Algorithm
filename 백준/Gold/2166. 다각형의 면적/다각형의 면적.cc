#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int n;
vector<pair<double, double>> v;

double getArea(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
    double ret = 0.0;
    return ((a.first * b.second + b.first * c.second + c.first * a.second) -
            (b.first * a.second + c.first * b.second + a.first * c.second)) /
           2;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);

    for (auto &a : v) cin >> a.first >> a.second;

    double res = 0;

    for (int i = 1; i < n; i++) {
        res += getArea(v[0], v[i - 1], v[i]);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(res);
    return 0;
}