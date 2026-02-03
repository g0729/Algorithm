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

    int n, k;
    string s;
    cin >> n >> s >> k;
    if (n < k) {

        bool flag = true;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                flag = false;
            }
        }

        if (!flag)
            cout << "NO";
        else
            cout << "YES";
        return 0;
    }

    for (int i = n - k; i < n; i++) {
        if (s[i] == '1') {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}