#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool check(vector<int> &cnt, vector<int> &res) {
    for (int i = 0; i < 26; i++) {
        if (res[i] != cnt[i]) return false;
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        vector<int> cnt(26);
        vector<int> res(26);
        for (int i = 0; i < b.length(); i++) {
            cnt[a[i] - 'a']++;
            res[b[i] - 'a']++;
        }

        if (check(cnt, res)) {
            cout << "YES\n";
            continue;
        }
        bool flag = true;
        for (int i = b.length(); i < a.length(); i++) {
            cnt[a[i] - 'a']++;
            cnt[a[i - (int)b.length()] - 'a']--;

            if (check(cnt, res)) {
                cout << "YES";
                flag = false;
                break;
            }
        }

        if (flag) cout << "NO";

        cout << "\n";
    }
    return 0;
}