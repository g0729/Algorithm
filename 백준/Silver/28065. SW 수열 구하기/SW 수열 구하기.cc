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
    int left = 1, right = n;

    while (left < right) {
        cout << left++ << " ";
        if (left > right) break;
        cout << right-- << " ";
    }

    if (n % 2) cout << (n + 1) / 2;
    return 0;
}