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

    void insert(bitset<27> &bits, int idx)
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
    void erase(bitset<27> &bits, int idx, int num)
    {
        cnt -= num;
        if (idx == -1)
            return;
        node[bits[idx]]->erase(bits, idx - 1, num);
        if (node[bits[idx]]->cnt == 0)
        {
            delete node[bits[idx]];
            node[bits[idx]] = NULL;
        }
    }
    void search(bitset<27> &bits, int idx, int mode)
    {
        if (idx == -1)
            return;

        int now = bits[idx];
        int target = (now + 1 + mode) % 2;

        if (node[target])
        {
            bits[idx] = !mode;
            node[target]->search(bits, idx - 1, mode);
        }
        else
        {
            bits[idx] = mode;
            node[!target]->search(bits, idx - 1, mode);
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
        Trie *root = new Trie;
        map<int, int> ma;
        set<int> se;
        int n, q;
        cin >> n >> q;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            ma[a]++;
            se.insert(a);
            bitset<27> bits(a);
            root->insert(bits, 26);
        }

        int op, a, num, min, max;
        bitset<27> bits;
        while (q--)
        {
            cin >> op;
            switch (op)
            {
            case 1:
                cin >> a;
                bits = a;
                root->search(bits, 26, 1);
                cout << bits.to_ulong() << "\n";
                break;
            case 2:
                cin >> a;
                bits = a;
                root->search(bits, 26, 0);
                cout << bits.to_ulong() << "\n";
                break;
            case 3:
                cin >> a;
                ma[a]++;
                se.insert(a);
                bits = a;
                root->insert(bits, 26);
                cout << se.size() << "\n";
                break;
            case 4:
                min = ma.begin()->first;
                num = ma.begin()->second;
                se.erase(min);
                ma.erase(min);
                bits = min;
                root->erase(bits, 26, num);
                cout << min << "\n";
                break;
            case 5:
                max = ma.rbegin()->first;
                num = ma.rbegin()->second;
                se.erase(max);
                ma.erase(max);
                bits = max;
                root->erase(bits, 26, num);
                cout << max << "\n";
                break;
            }
        }
        delete root;
    }

    return 0;
}