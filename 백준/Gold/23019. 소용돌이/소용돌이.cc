#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n;
void f(int layer_idx, vector<string> &v, vector<string> &layers) {
    string s;
    int n_size = v.size();
    int start = layer_idx;
    int end = n_size - 1 - layer_idx;

    if (start > end) return;
    if (start == end) {
        layers.push_back(string(1, v[start][start]));
        return;
    }

    for (int c = start; c < end; ++c) s.push_back(v[start][c]);
    for (int r = start; r < end; ++r) s.push_back(v[r][end]);
    for (int c = end; c > start; --c) s.push_back(v[end][c]);
    for (int r = end; r > start; --r) s.push_back(v[r][start]);
    layers.push_back(s);
    f(layer_idx + 1, v, layers);
}

void ff(int start_point, int layer_size, vector<vector<string>> &blocks, string &min_string, string &max_string) {

    for (int i = 0; i < (1 << layer_size); i++) {
        string s;
        for (int j = 0; j < layer_size; j++) {
            int cur_dir = (i >> j) & 1;
            s += blocks[j][start_point * 2 + cur_dir];
        }

        if (min_string == "" || min_string > s) {
            min_string = s;
        }
        if (max_string == "" || max_string < s) {
            max_string = s;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        vector<string> v(n);
        for (auto &a : v) cin >> a;
        vector<string> layers;

        f(0, v, layers);

        vector<vector<string>> blocks((int)layers.size(), vector<string>(8));

        for (int i = 0; i < layers.size(); i++) {
            string cur = layers[i];
            string reversed = cur;
            reverse(reversed.begin(), reversed.end());
            reversed = reversed.back() + reversed;

            reversed.pop_back();
            cur = cur + cur;
            reversed = reversed + reversed;

            for (int j = 0; j < 4; j++) {
                int start = (int)layers[i].length() / 4 * j;
                string temp = cur.substr(start, (int)layers[i].length());
                blocks[i][j * 2] = temp;
                temp = reversed.substr(start, (int)layers[i].length());
                blocks[i][(1 - 2 * j + 8) % 8] = temp;
            }
        }

        string min_string, max_string;

        for (int i = 0; i < 4; i++) {
            ff(i, (int)layers.size(), blocks, min_string, max_string);
        }

        cout << max_string << " " << min_string << "\n";
    }
    return 0;
}