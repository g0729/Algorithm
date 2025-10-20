#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

vector<bitset<30>> v;
int n, m;
bitset<30> alpha((1 << 31) - 1);

int cal() {
    int res = 0;
    for (auto &a : v) {
        if ((a & alpha) == a) {
            res++;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        bitset<30> temp;
        cin >> s;

        for (auto &c : s) {
            temp[c - 'a'] = true;
        }

        v.push_back(temp);
    }

    while (m--) {
        int a;
        char c;
        cin >> a >> c;

        alpha[c - 'a'] = (a == 1 ? false : true);

        cout << cal() << "\n";
    }
    return 0;
}