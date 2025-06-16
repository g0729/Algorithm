#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Trie {

    vector<Trie *> v;

    Trie() : v(26, nullptr) {};
    ~Trie() {
        for (auto &a : v)
            if (a) delete a;
    };
    void insert(string &s, int idx, string &res, bool &flag) {
        if (idx == s.length()) return;

        if (!flag) res.push_back(s[idx]);
        if (v[s[idx] - 'a'] == nullptr) {
            if (!flag) flag = true;
            Trie *temp = new Trie;
            v[s[idx] - 'a'] = temp;
        }

        v[s[idx] - 'a']->insert(s, idx + 1, res, flag);
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    Trie *root = new Trie;
    map<string, int> ma;
    while (n--) {

        string s, res;
        bool flag = false;
        cin >> s;

        root->insert(s, 0, res, flag);
        ma[s]++;
        if (!flag && ma[s] != 1) res += to_string(ma[s]);
        cout << res << "\n";
    }
    return 0;
}