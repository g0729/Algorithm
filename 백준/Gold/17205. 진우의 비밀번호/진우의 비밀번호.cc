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

    ll res = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < (n - i); j++) {
            res += pow(26LL, j) * (s[i] - 'a');
        }
        res += 1;
    }
    cout << res;
    return 0;
}