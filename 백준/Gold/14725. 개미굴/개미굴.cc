#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

struct Trie
{
    map<string, Trie *> ma;

    void insert(vector<string> &v, int idx)
    {
        if (idx == v.size())
            return;

        if (ma.find(v[idx]) == ma.end())
        {
            Trie *temp = new Trie;
            ma.insert({v[idx], temp});
        }
        ma[v[idx]]->insert(v, idx + 1);
    }
    void search(int depth)
    {
        for (auto i : ma)
        {
            for (int j = 0; j < depth; j++)
                cout << "--";
            cout << i.first << "\n";
            i.second->search(depth + 1);
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Trie *root = new Trie;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vector<string> v;
        for (int j = 0; j < a; j++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        root->insert(v, 0);
    }
    root->search(0);

    return 0;
}