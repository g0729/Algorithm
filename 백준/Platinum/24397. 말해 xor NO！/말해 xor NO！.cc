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
    int cnt;
    Trie *node[2];

    Trie()
    {
        this->cnt = 0;
        this->node[0] = this->node[1] = NULL;
    }

    ~Trie()
    {
        for (auto it : node)
            if (it)
                delete it;
    }

    void insert(bitset<32> &bits, int idx)
    {
        cnt++;
        if (idx == -1)
            return;
        if (node[bits[idx]] == NULL)
        {
            Trie *temp = new Trie;
            node[bits[idx]] = temp;
        }
        node[bits[idx]]->insert(bits, idx - 1);
    }

    void search(bitset<32> now, bitset<32> &target, ll &res, int idx)
    {
        if (idx == -1)
        {
            res += cnt;
            return;
        }
        for (int i = 0; i < 2; i++)
        {
            if (node[i] == NULL)
                continue;
            int cur = now[idx] ^ i;
            if (cur == target[idx])
            {
                bitset<32> next(now);
                next[idx] = cur;
                node[i]->search(next, target, res, idx - 1);
            }
            else if (cur && !target[idx])
                continue;
            else if (!cur && target[idx])
                res += node[i]->cnt;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    Trie *root = new Trie;
    bitset<32> target(k - 1);
    vector<int> v(n + 1);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        bitset<32> bits(a);
        root->insert(bits, 31);
    }

    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        ll res = 0;
        bitset<32> bits(a);
        root->search(bits, target, res, 31);
        ans += res;
    }

    cout << ans;
    return 0;
}