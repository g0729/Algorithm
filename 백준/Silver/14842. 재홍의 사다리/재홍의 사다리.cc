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

    double W, H;
    long long N;

    cin >> H >> W >> N;
    double answer = 0;

    if (N % 2 == 0) {
        answer = W * (N - 2) / 2.0;
    } else {
        answer = W * (N - 1) * (N - 1) / (2.0 * N);
    }

    cout << fixed << setprecision(6) << answer << "\n";

    return 0;
}