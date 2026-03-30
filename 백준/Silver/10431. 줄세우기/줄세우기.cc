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
        int T;
        cin >> T;
        vector<int> heights(20);
        for (int i = 0; i < 20; i++) {
            cin >> heights[i];
        }

        vector<int> line;
        int total_steps = 0;

        for (int i = 0; i < 20; i++) {
            int current_height = heights[i];
            bool inserted = false;

            for (int j = 0; j < line.size(); j++) {
                if (line[j] > current_height) {
                    total_steps += (line.size() - j);
                    line.insert(line.begin() + j, current_height);
                    inserted = true;
                    break;
                }
            }

            if (!inserted) {
                line.push_back(current_height);
            }
        }

        cout << T << " " << total_steps << "\n";
    }
    return 0;
}