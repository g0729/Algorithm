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

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

bool f(int n) {

    for (int i = 0; i < 100; i++) {
        string s = to_string(n);
        int sum = 0;

        for (auto &c : s) {
            int temp = (c - '0');
            sum += temp * temp;
        }

        if (sum == 1) return true;

        n = sum;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int a, b;
        cin >> b >> a;

        cout << i << " " << a << " ";
        if (!isPrime(i)) {
            cout << "NO\n";
            continue;
        }

        if (f(a))
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}