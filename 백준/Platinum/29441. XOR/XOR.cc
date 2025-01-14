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
    Trie *node[2];

    Trie()
    {
        node[0] = node[1] = NULL;
    }

    void insert(bitset<30> &bits, int idx)
    {
        if (idx == -1)
            return;

        if (node[bits[idx]] == NULL)
        {
            Trie *temp = new Trie;
            node[bits[idx]] = temp;
        }
        node[bits[idx]]->insert(bits, idx - 1);
    }

    void search(bitset<30> &bits, int idx, bitset<30> &res)
    {
        if (idx == -1)
            return;
        if (node[!bits[idx]])
        {
            res[idx] = !bits[idx];
            node[!bits[idx]]->search(bits, idx - 1, res);
        }
        else
        {
            res[idx] = bits[idx];
            node[bits[idx]]->search(bits, idx - 1, res);
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    Trie *root = new Trie;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        bitset<30> bits(a);
        root->insert(bits, 29);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        bitset<30> bits(a), res;
        root->search(bits, 29, res);
        cout << res.to_ulong() << " ";
    }

    return 0;
}