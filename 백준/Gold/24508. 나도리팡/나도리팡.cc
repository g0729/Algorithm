#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k, t;
    cin >> n >> k >> t;

    vector<ll> v(n);
    for (auto &a : v) cin >> a;

    sort(v.begin(), v.end());

    ll left = 0, right = n - 1;

    if (accumulate(v.begin(), v.end(), 0ll) % k) {
        cout << "NO";
        return 0;
    }

    while (left < right && t > 0) {

        if (v[left] + v[right] < k) {
            v[right] += v[left], t -= v[left], v[left] = 0, left++;
        } else {
            v[left] -= k - v[right], t -= (k - v[right]), v[right] = 0, right--;
        }
    }

    if (t < 0) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (v[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}