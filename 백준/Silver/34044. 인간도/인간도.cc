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

    if (n == 1) {
        cout << "-1";
        return 0;
    }
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) cout << "1331";
    } else {
        cout << "374143";
        for (int i = 0; i < (n - 3) / 2; i++) cout << "1331";
    }
    return 0;
}