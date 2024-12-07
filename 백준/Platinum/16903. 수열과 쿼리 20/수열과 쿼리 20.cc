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
        for (int i = 0; i < 2; i++)
        {
            if (this->node[i])
                delete node[i];
        }
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

    void search(int depth, bitset<32> &bits)
    {
        if (depth == -1)
            return;

        int now = bits[depth];
        int target = (now + 1) % 2;

        if (node[target])
        {
            bits[depth] = 1;
            node[target]->search(depth - 1, bits);
        }
        else
        {
            bits[depth] = 0;
            node[now]->search(depth - 1, bits);
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    Trie *root = new Trie;
    bitset<32> zero(0);
    root->insert(zero, 31);
    while (q--)
    {
        int op, num;
        cin >> op >> num;
        bitset<32> bits(num);
        if (op == 1)
            root->insert(bits, 31);
        else if (op == 2)
            root->erase(bits, 31);
        else
        {
            root->search(31, bits);
            int res = bits.to_ulong();
            cout << res << "\n";
        }
    }
    return 0;
}