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

    string a, b;
    cin >> a >> b;

    int b_min = 1e9;
    int b_sum = 0;

    for (int i = 0; i < b.length(); i++) {
        b_sum += b[i] == '(' ? 1 : -1;
        b_min = min(b_min, b_sum);
    }

    vector<int> a_sum((int)a.length());
    vector<int> a_min((int)a.length(), 1e6);

    for (int i = 0; i < a.length(); i++) {
        a_sum[i] = (i == 0 ? 0 : a_sum[i - 1]) + (a[i] == '(' ? 1 : -1);
    }
    a_min[a.length() - 1] = a_sum[a.length() - 1];

    for (int i = a.length() - 2; i >= 0; i--) {
        a_min[i] = min(a_min[i + 1], a_sum[i]);
    }

    if (a_sum[a.length() - 1] + b_sum != 0) {
        cout << "0";
        return 0;
    }
    for (int i = 0; i < a.length() - 1; i++) {
        if (a_sum[i] < 0) break;
        if (a_sum[i] + b_min < 0) continue;

        if (a_min[i + 1] + b_sum >= 0) {
            cout << "1";
            return 0;
        }
    }

    cout << "0";
    return 0;
}