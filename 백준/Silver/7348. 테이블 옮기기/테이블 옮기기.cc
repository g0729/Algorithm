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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> hall(201);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            for (int j = (min(a, b) + 1) / 2; j <= (max(a, b) + 1) / 2; j++) {
                hall[j]++;
            }
        }

        cout << *max_element(hall.begin(), hall.end()) * 10 << "\n";
    }
    return 0;
}