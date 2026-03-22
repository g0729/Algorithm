#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

map<int, int> ma;
bool isAble(int n, vector<bool> &nums) {
    string s = to_string(n);
    for (int i = 0; i < s.length(); i++) {
        if (nums[s[i] - '0'] == false) return false;
    }

    return true;
}
int solve(int k, vector<bool> &nums) {
    if (isAble(k, nums)) return 0;

    if (ma.count(k)) return ma[k];

    int minCnt = 1e9;
    for (int i = 2; i * i <= k; i++) {
        if (k % i != 0) continue;

        int res1 = solve(i, nums);
        int res2 = solve(k / i, nums);

        if (res1 != 1e9 && res2 != 1e9) {
            minCnt = min(minCnt, res1 + res2 + 1);
        }
    }

    return ma[k] = minCnt;
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
        vector<bool> nums(10);

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            nums[a] = true;
        }

        ma.clear();

        int m;
        cin >> m;

        while (m--) {
            int k;
            cin >> k;

            int res = solve(k, nums);

            if (res == 1e9)
                cout << "-1";
            else
                cout << res;

            cout << "\n";
        }
    }
    return 0;
}