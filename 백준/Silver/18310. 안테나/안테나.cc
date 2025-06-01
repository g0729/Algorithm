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
    vector<int> v(n);
    for (auto &a : v) cin >> a;

    sort(v.begin(), v.end());

    if (v.size() % 2 == 0) {
        int sum_1 = 0, sum_2 = 0;

        for (int i = 0; i < n; i++) {
            sum_1 += abs(v[i] - v[n / 2 - 1]);
            sum_2 += abs(v[i] - v[n / 2]);
        }

        if (sum_1 <= sum_2)
            cout << v[n / 2 - 1];
        else
            cout << v[n / 2];

    } else
        cout << v[n / 2];
    return 0;
}