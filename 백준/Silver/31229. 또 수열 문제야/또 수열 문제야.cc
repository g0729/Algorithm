#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

bool isPrime(int a) {
    if (a == 1) return false;
    if (a == 2 | a == 3) return true;

    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int idx = 0, i = 2; idx < n; i++) {

        if (isPrime(i)) {
            cout << i << " ";
            idx++;
        }
    }
    return 0;
}