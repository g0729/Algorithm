#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

struct Point {
    double x, y, z;
};

Point A, B, C;

double getDistance(double target) {
    Point t;
    t.x = A.x + (B.x - A.x) * target;
    t.y = A.y + (B.y - A.y) * target;
    t.z = A.z + (B.z - A.z) * target;

    double diffX = C.x - t.x;
    double diffY = C.y - t.y;
    double diffZ = C.z - t.z;

    return diffX * diffX + diffY * diffY + diffZ * diffZ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z;

    double lo = 0.0, hi = 1.0;

    for (int i = 0; i < 100; i++) {

        double p = (lo * 2 + hi) / 3;
        double q = (lo + hi * 2) / 3;

        if (getDistance(p) <= getDistance(q))
            hi = q;
        else
            lo = p;
    }

    cout << fixed << setprecision(10) << sqrt(getDistance(lo));
    return 0;
}