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

    int n;
    cin >> n;
    string s;
    cin >> s;
    string res = s;

    for (int i = 0; i < n - 1; i++) {
        char c = 0;
        for (int j = i + 1; j < n; j++) {
            c = max(c, s[j]);
        }

        if (c <= s[i]) continue;

        for (int j = i + 1; j < n; j++) {
            if (s[j] == c) {
                string temp = s;
                reverse(temp.begin() + i, temp.begin() + j + 1);

                if (temp > res) res = temp;
            }
        }
    }

    cout << res;

    return 0;
}