#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

string toBinary(int n) {
    if (n == 0) return "0";
    string s;
    while (n) {
        s += (n & 1 ? '1' : '0');
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

int toDecimal(string s) {
    int ret = 0;
    int p = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '1') ret += p;
        p *= 2;
    }

    return ret;
}

int makePalindrome(int half, bool isOdd) {
    string s = toBinary(half);
    string p = s;
    reverse(p.begin(), p.end());

    if (isOdd) s.pop_back();
    s += p;
    return toDecimal(s);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "0";
            continue;
        }
        string s = toBinary(n);
        int len = s.length();
        vector<int> candidates;
        candidates.push_back((1 << (len - 1)) - 1);
        candidates.push_back((1 << len) + 1);

        int half = toDecimal(s.substr(0, (s.length() + 1) / 2));

        bool isOdd = (s.length() % 2 == 1);
        candidates.push_back(makePalindrome(half, isOdd));
        candidates.push_back(makePalindrome(half + 1, isOdd));
        candidates.push_back(makePalindrome(half - 1, isOdd));

        int res = 1e9;

        for (auto &candidate : candidates) {
            int diff = abs(candidate - n);
            res = min(res, diff);
        }

        cout << res << "\n";
    }
    return 0;
}