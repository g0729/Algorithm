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
        string num_str, mine;
        cin >> num_str >> mine;

        vector<int> num(n);
        for (int i = 0; i < n; i++) {
            num[i] = num_str[i] - '0';
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            if (mine[i] == '*') {
                res++;
                if (i - 1 >= 0) num[i - 1]--;
                num[i]--;
                if (i + 1 < n) num[i + 1]--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (mine[i] == '#') {
                bool can_place = true;
                if (i - 1 >= 0 && num[i - 1] <= 0) can_place = false;
                if (num[i] <= 0) can_place = false;
                if (i + 1 < n && num[i + 1] <= 0) can_place = false;

                if (can_place) {
                    res++;
                    if (i - 1 >= 0) num[i - 1]--;
                    num[i]--;
                    if (i + 1 < n) num[i + 1]--;
                }
            }
        }

        cout << res << "\n";
    }

    return 0;
}