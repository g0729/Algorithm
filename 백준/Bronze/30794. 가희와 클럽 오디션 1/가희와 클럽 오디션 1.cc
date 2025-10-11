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
    string s;
    cin >> n >> s;

    if (s == "miss") {
        cout << "0";
    } else if (s == "bad") {
        cout << 200 * n;
    } else if (s == "cool") {
        cout << 400 * n;
    } else if (s == "great") {
        cout << 600 * n;
    } else if (s == "perfect") {
        cout << 1000 * n;
    }
    return 0;
}