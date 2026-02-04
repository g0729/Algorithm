#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

bool isPrime(int n) {

    if (n <= 1) return false;
    if (n == 2) return true;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for (int i = k + 1; i <= 1000000; i += k) {
        if (isPrime(i)) {
            cout << i << " ";
            cnt++;
            if (cnt == n) break;
        }
    }

    return 0;
}