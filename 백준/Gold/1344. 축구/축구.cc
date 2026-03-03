#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
double dp[19][19][19];

bool isPrime(int a) {
    if (a <= 1) return false;
    if (a == 2 || a == 3) return true;

    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double a, b;
    cin >> a >> b;

    dp[0][0][0] = 1.0;
    double A = a / 100, B = b / 100;

    for (int i = 1; i <= 18; i++) {

        dp[i][0][0] = dp[i - 1][0][0] * (1 - A) * (1 - B);

        for (int j = 1; j <= 18; j++) {
            dp[i][0][j] = dp[i - 1][0][j - 1] * (1 - A) * B + dp[i - 1][0][j] * (1 - A) * (1 - B);
            dp[i][j][0] = dp[i - 1][j - 1][0] * A * (1 - B) + dp[i - 1][j][0] * (1 - A) * (1 - B);
        }
        for (int j = 1; j <= 18; j++) {
            for (int k = 1; k <= 18; k++) {

                dp[i][j][k] = dp[i - 1][j][k] * (1 - A) * (1 - B) + dp[i - 1][j - 1][k] * A * (1 - B) +
                              dp[i - 1][j][k - 1] * (1 - A) * B + dp[i - 1][j - 1][k - 1] * A * B;
            }
        }
    }

    double res = 0.0;

    for (int i = 0; i <= 18; i++) {
        for (int j = 0; j <= 18; j++) {
            if (dp[18][i][j] >= 1.0) cout << i << " " << j << "\n";
            if (isPrime(i) || isPrime(j)) res += dp[18][i][j];
        }
    }

    cout << res;
    return 0;
}