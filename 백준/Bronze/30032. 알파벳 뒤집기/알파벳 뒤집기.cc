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

    int n, op;
    cin >> n >> op;

    map<char, vector<char>> ma = {{'d', {'q', 'b'}}, {'b', {'p', 'd'}}, {'q', {'d', 'p'}}, {'p', {'b', 'q'}}};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto &c : s) {
            c = ma[c][op - 1];
        }
        cout << s << "\n";
    }

    return 0;
}