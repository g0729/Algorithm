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
    vector<int> v(n + 1);
    vector<int> acc_sum(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) acc_sum[i] = acc_sum[i - 1] + v[i];

    int res = 0, res_diff = 1e9;

    for (int i = 1; i <= n; i++) {
        int left = 1, right = n;

        while (left < right) {
            int diff = (acc_sum[right] - acc_sum[i]) - (acc_sum[i] - acc_sum[left - 1]);

            if (abs(diff) <= res_diff) {
                if (abs(diff) == res_diff)
                    res = max(res, acc_sum[right] - acc_sum[left - 1]);
                else {
                    res_diff = abs(diff);
                    res = acc_sum[right] - acc_sum[left - 1];
                }
            }

            if (diff < 0)
                left++;
            else
                right--;
        }
    }
    cout << res;

    return 0;
}