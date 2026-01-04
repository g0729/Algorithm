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
    int n;
    cin >> n;
    vector<int> v(14);

    for (auto &a : v) cin >> a;

    int bnp = n, bnp_stock = 0;
    for (int i = 0; i < 13; i++) {
        if (bnp >= v[i]) {
            bnp_stock += bnp / v[i];
            bnp = bnp % v[i];
        }
    }
    bnp = bnp + bnp_stock * v[13];

    int timing = n, timing_stock = 0;

    int seq = (v[1] > v[0] ? 1 : (v[1] == v[0] ? 0 : -1));

    for (int i = 2; i < 13; i++) {
        if (v[i] == v[i - 1])
            seq = 0;
        else if (v[i] > v[i - 1]) {
            if (seq > 0)
                seq += 1;
            else if (seq <= 0)
                seq = 1;

            if (seq >= 3) {
                timing += timing_stock * v[i];
                timing_stock = 0;
            }
        } else if (v[i] < v[i - 1]) {
            if (seq < 0)
                seq -= 1;
            else if (seq >= 0)
                seq = -1;

            if (seq <= -3) {
                timing_stock += timing / v[i];
                timing = timing % v[i];
            }
        }
    }
    timing = timing + timing_stock * v[13];

    cout << (bnp == timing ? "SAMESAME" : (bnp > timing ? "BNP" : "TIMING"));
    return 0;
}