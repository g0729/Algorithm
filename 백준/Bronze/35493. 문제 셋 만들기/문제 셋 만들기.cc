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
    bool isOdd = false;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2) isOdd = true;
    }

    if (n == 1 && isOdd) {
        cout << "NO";
        return 0;
    }

    cout << "YES";
    return 0;
}