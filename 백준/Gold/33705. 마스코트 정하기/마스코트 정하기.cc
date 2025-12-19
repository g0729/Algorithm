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
    int total_sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] = (v[i] == 1 ? 1 : -1);
        total_sum += v[i];
    }

    int min_sum = v[1];
    int sum = 0;

    for (int i = 1; i < n; i++) {
        sum = min(v[i], sum + v[i]);
        min_sum = min(min_sum, sum);
    }
    sum = 0;
    for (int i = 2; i <= n; i++) {
        sum = min(v[i], sum + v[i]);
        min_sum = min(min_sum, sum);
    }

    if (total_sum >= 0)
        cout << "0";
    else if (total_sum >= min_sum)
        cout << "1";
    else
        cout << "2";
    return 0;
}