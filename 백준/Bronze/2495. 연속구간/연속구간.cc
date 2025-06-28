#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        int cnt = 1;
        int res = 1;
        for (int j = 1; j < s.length(); j++) {
            if (s[j] == s[j - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            res = max(res, cnt);
        }

        cout << res << "\n";
    }

    return 0;
}