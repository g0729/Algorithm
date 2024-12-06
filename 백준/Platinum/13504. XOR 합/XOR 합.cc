#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct Trie
{
    map<char, Trie *> ma;

    ~Trie()
    {
        for (auto it : ma)
            delete it.second;
    }
    void insert(vector<char> &v, int idx)
    {
        if (idx == 32)
            return;
        if (ma.find(v[idx]) == ma.end())
        {
            Trie *temp = new Trie;
            ma.insert({v[idx], temp});
        }
        ma[v[idx]]->insert(v, idx + 1);
    }

    void search(int depth, string &res)
    {
        char now = res[depth];
        char target = (now - '0' + 1) % 2 + '0';
        if (ma.size() == 0)
            return;
        if (ma.find(target) == ma.end())
        {
            res[depth] = '0';
            ma[now]->search(depth + 1, res);
        }
        else
        {
            res[depth] = '1';
            ma[target]->search(depth + 1, res);
        }
    }
};

int bin_to_decimal(string &s)
{
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int idx = s.length() - 1 - i;

        if (s[idx] == '0')
            continue;
        res += (1 << i);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        int ans = 0;
        Trie *root = new Trie;

        vector<char> init(32);
        for (int i = 0; i < 32; i++)
            init[i] = '0';
        root->insert(init, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            v[i] ^= v[i - 1];

            bitset<32> bits(v[i]);
            vector<char> String;
            string s = bits.to_string();
            for (int j = 0; j < s.length(); j++)
                String.push_back(s[j]);

            root->insert(String, 0);
            root->search(0, s);
            int res = bin_to_decimal(s);
            ans = max(ans, res);
        }

        cout << ans << "\n";
        delete root;
    }
    return 0;
}