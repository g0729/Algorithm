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

    void insert(vector<char> &v, int idx)
    {
        if (idx == 31)
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

    int n;
    cin >> n;
    Trie *root = new Trie;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
        bitset<31> bits(a);
        vector<char> String;
        string s = bits.to_string();
        for (int j = 0; j < s.length(); j++)
            String.push_back(s[j]);
        root->insert(String, 0);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        bitset<31> bits(v[i]);
        string s = bits.to_string();
        root->search(0, s);
        int res = bin_to_decimal(s);
        ans = max(ans, res);
    }

    cout << ans << "\n";
    delete root;

    return 0;
}