#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

vector<int> v;
map<int, int> ma;
int n, m, k;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ma[a] = b;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    while (m--) {
        int op, a, b;
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            ma[a] = b;
            v.insert(lower_bound(v.begin(), v.end(), a), a);
        } else if (op == 2) {
            cin >> a >> b;

            int idx = lower_bound(v.begin(), v.end(), a) - v.begin();

            if (v.size() == 1 || idx == 0) {
                if (abs(a - v[idx]) > k)
                    continue;
                else
                    ma[v[idx]] = b;
            } else if (idx == v.size()) {
                if (abs(a - v[idx - 1]) > k)
                    continue;
                else
                    ma[v[idx - 1]] = b;
            } else {

                int diffA = abs(a - v[idx]), diffB = abs(a - v[idx - 1]);

                if (diffA > k && diffB > k)
                    continue;
                else if (diffA == diffB)
                    continue;
                else if (diffA < diffB)
                    ma[v[idx]] = b;
                else if (diffA > diffB)
                    ma[v[idx - 1]] = b;
            }

        } else if (op == 3) {
            cin >> a;

            int idx = lower_bound(v.begin(), v.end(), a) - v.begin();

            if (v.size() == 1 || idx == 0) {
                if (abs(a - v[idx]) > k)
                    cout << "-1";
                else
                    cout << ma[v[idx]];
            } else if (idx == v.size()) {
                if (abs(a - v[idx - 1]) > k)
                    cout << "-1";
                else
                    cout << ma[v[idx - 1]];
            } else {

                int diffA = abs(a - v[idx]), diffB = abs(a - v[idx - 1]);

                if (diffA > k && diffB > k)
                    cout << "-1";
                else if (diffA == diffB)
                    cout << "?";
                else if (diffA < diffB)
                    cout << ma[v[idx]];
                else if (diffA > diffB)
                    cout << ma[v[idx - 1]];
            }

            cout << "\n";
        }
    }
    return 0;
}