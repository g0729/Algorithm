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
    map<string, Trie *> ma;

    void insert(vector<string> &v, int idx)
    {
        if (v.size() == idx)
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
            {
                cout << " ";
            }
            cout << i.first << "\n";
            i.second->search(depth + 1);
        }
    }
};

vector<string> parser(string &s)
{
    vector<string> res;
    string temp;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '\\')
        {
            res.push_back(temp);
            temp = "";
        }
        else
            temp.push_back(s[i]);
    }

    if (!temp.empty())
        res.push_back(temp);

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Trie *root = new Trie;

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        vector<string> parsed = parser(s);
        root->insert(parsed, 0);
    }
    root->search(0);
    return 0;
}