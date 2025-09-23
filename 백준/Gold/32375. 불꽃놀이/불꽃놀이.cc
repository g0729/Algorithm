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
    cin >> n >> k;

    vector<int> v(n);

    for (auto &a : v) cin >> a;

    sort(v.begin(), v.end());

    int idx = 0;

    while (idx < n && v[idx] < k) idx++;

    int res = n - idx;

    int left = 0, right = idx - 1;

    while (left < right) {
        int sum = v[left] + v[right];

        if (sum >= k)
            res++, right--, left++;
        else
            left++;
    }

    cout << ((res == 0) ? -1 : res);
    return 0;
}