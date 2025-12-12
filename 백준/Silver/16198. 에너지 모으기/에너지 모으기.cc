#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int res;

void f(vector<int> v, int score) {

    if (v.size() == 2) {
        res = max(res, score);
        return;
    }

    for (int i = 1; i < v.size() - 1; i++) {
        vector<int> temp = v;
        int next_score = score + v[i - 1] * v[i + 1];
        temp.erase(temp.begin() + i);
        f(temp, next_score);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &a : v) cin >> a;

    f(v, 0);

    cout << res;
    return 0;
}