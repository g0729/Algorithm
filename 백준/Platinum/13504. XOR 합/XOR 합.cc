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
    ~Trie()
    {
        for (int i = 0; i < 2; i++)
            if (node[i])
                delete node[i];
    }

    void insert(bitset<32> &bits, int idx)
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

    void search(bitset<32> &bits, int idx)
    {
        if (idx == -1)
            return;
        int now = bits[idx];
        int target = (now + 1) % 2;

        if (node[target])
        {
            bits[idx] = 1;
            node[target]->search(bits, idx - 1);
        }
        else
        {
            bits[idx] = 0;
            node[now]->search(bits, idx - 1);
        }
    }
};
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
        Trie *root = new Trie;
        vector<int> v(n + 1);
        bitset<32> zero(0);
        root->insert(zero, 31);

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            v[i] ^= v[i - 1];
            bitset<32> bits(v[i]);
            root->insert(bits, 31);
            root->search(bits, 31);
            int res = bits.to_ulong();
            ans = max(ans, res);
        }

        cout << ans << "\n";
        delete root;
    }
    return 0;
}