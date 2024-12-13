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
        cnt = 0;
        node[0] = node[1] = NULL;
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

    void erase(bitset<32> &bits, int idx)
    {
        cnt--;
        if (idx == -1)
            return;
        node[bits[idx]]->erase(bits, idx - 1);
        if (node[bits[idx]]->cnt == 0)
        {
            delete node[bits[idx]];
            node[bits[idx]] = NULL;
        }
    }

    void search(bitset<32> &bits, int idx, int num)
    {
        int now = bits[idx];
        int target = !now;

        if (idx == -1)
            return;
        if (node[now] != NULL && node[target] != NULL)
        {
            if (node[target]->cnt >= num)
            {
                bits[idx] = 1;
                node[target]->search(bits, idx - 1, num);
            }
            else
            {
                bits[idx] = 0;
                node[now]->search(bits, idx - 1, num - node[target]->cnt);
            }
        }
        else
        {
            int next = node[0] != NULL ? 0 : 1;
            bits[idx] = bits[idx] ^ next;
            node[next]->search(bits, idx - 1, num);
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
    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        bitset<32> bits(v[i]);
        root->insert(bits, 31);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int op, i, x;
        cin >> op >> i >> x;
        if (op == 1)
        {
            bitset<32> bits(v[i]);
            root->erase(bits, 31);
            bits = x;
            root->insert(bits, 31);
            v[i] = x;
        }
        else
        {
            bitset<32> bits(x);
            root->search(bits, 31, i);
            cout << bits.to_ulong() << "\n";
        }
    }
    return 0;
}