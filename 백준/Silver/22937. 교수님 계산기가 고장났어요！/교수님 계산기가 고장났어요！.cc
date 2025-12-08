#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

unsigned long long parse(string &s) {
    string temp = "";
    for (auto &c : s) {
        if ('0' <= c && c <= '9') temp += c;
    }

    return stoull(temp);
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    bool is_negative = (s1[0] == '-') ^ (s2[0] == '-');

    unsigned long long a = parse(s1);
    unsigned long long b = parse(s2);

    unsigned long long result = a * b;

    if (result == 0) {
        cout << "0.";
        for (int i = 0; i < 18; ++i) cout << "0";
        cout << "\n";
        return;
    }

    string ret = to_string(result);

    if (ret.length() <= 18) {
        string padding = "";
        for (int i = 0; i < 18 - ret.length(); ++i) {
            padding += "0";
        }
        ret = "0." + padding + ret;
    } else {
        ret.insert(ret.length() - 18, ".");
    }

    if (is_negative) {
        cout << "-";
    }
    cout << ret << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}