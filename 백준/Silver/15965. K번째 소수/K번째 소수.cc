#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 10000000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

vector<bool> isPrime(MAX, true);

void f() {
    isPrime[1] = isPrime[0] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) isPrime[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    f();

    int a;
    cin >> a;

    for (int i = 1; i < MAX; i++) {
        if (isPrime[i]) {
            a--;
            if (a == 0) {
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}