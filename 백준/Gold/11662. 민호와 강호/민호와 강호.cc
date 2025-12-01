#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

struct Point {
    double x, y;
};

Point A, B, C, D;

double getDistance(double t) {
    Point A_t, B_t;

    A_t.x = A.x + (B.x - A.x) * t;
    A_t.y = A.y + (B.y - A.y) * t;

    B_t.x = C.x + (D.x - C.x) * t;
    B_t.y = C.y + (D.y - C.y) * t;

    double diffX = B_t.x - A_t.x;
    double diffY = B_t.y - A_t.y;

    return diffX * diffX + diffY * diffY;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

    double lo = 0.0, hi = 1.0;

    for (int i = 0; i < 100; i++) {
        double p = (lo * 2 + hi) / 3;
        double q = (lo + hi * 2) / 3;

        double distP = getDistance(p);
        double distQ = getDistance(q);

        if (distP <= distQ)
            hi = q;
        else
            lo = p;
    }

    cout << fixed << setprecision(10) << sqrt(getDistance(lo)) << "\n";
    return 0;
}