#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
vector<int> v(8);
vector<int> permu = {0, 1, 2, 3, 4, 5, 6, 7};
const double PI = acos(-1.0);
const double EPS = 1e-9;
double ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
    double res = (a.first * b.second + b.first * c.second + c.first * a.second) -
                 (b.first * a.second + c.first * b.second + a.first * c.second);
    return res;
}
bool isConvex() {
    vector<pair<double, double>> points(8);

    for (int i = 0; i < 8; i++) {
        double rad = i * PI / 4.0;
        double dist = v[permu[i]];
        points[i] = {dist * cos(rad), dist * sin(rad)};
    }

    for (int i = 0; i < 8; i++) {
        double val = ccw(points[(i + 7) % 8], points[i], points[(i + 1) % 8]);
        if (val < -EPS) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int &a : v) cin >> a;
    int res = 0;
    do {
        if (isConvex()) res++;
    } while (next_permutation(permu.begin(), permu.end()));
    cout << res;
    return 0;
}