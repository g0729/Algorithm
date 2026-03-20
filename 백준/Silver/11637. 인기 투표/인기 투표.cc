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

        vector<int> votes(n);
        int total_votes = 0;
        int max_vote = -1;
        int max_idx = -1;

        for (int i = 0; i < n; ++i) {
            cin >> votes[i];
            total_votes += votes[i];

            if (votes[i] > max_vote) {
                max_vote = votes[i];
                max_idx = i + 1;
            }
        }

        int max_count = 0;
        for (int i = 0; i < n; ++i) {
            if (votes[i] == max_vote) {
                max_count++;
            }
        }

        if (max_count > 1) {
            cout << "no winner\n";
        } else {
            if (max_vote > total_votes / 2) {
                cout << "majority winner " << max_idx << "\n";
            } else {
                cout << "minority winner " << max_idx << "\n";
            }
        }
    }

    return 0;
}