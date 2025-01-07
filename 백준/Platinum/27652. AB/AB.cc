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
    Trie *node[26];
    Trie()
    {
        cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            node[i] = NULL;
        }
    }

    void insert(string &s, int idx)
    {
        cnt++;
        if (idx == s.length())
            return;
        int cur = s[idx] - 'a';

        if (node[cur] == NULL)
        {
            Trie *temp = new Trie;
            node[cur] = temp;
        }
        node[cur]->insert(s, idx + 1);
    }

    void erase(string &s, int idx)
    {
        cnt--;
        if (idx == s.length())
            return;
        int cur = s[idx] - 'a';

        node[cur]->erase(s, idx + 1);
        if (node[cur]->cnt == 0)
        {
            delete node[cur];
            node[cur] = NULL;
        }
    }

    void search(string &s, int idx, vector<int> &v)
    {
        if (idx == s.length())
            return;

        int cur = s[idx] - 'a';

        if (node[cur] == NULL)
            return;

        v[idx] = node[cur]->cnt;
        node[cur]->search(s, idx + 1, v);
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Trie *A = new Trie;
    Trie *B = new Trie;

    int q;
    cin >> q;
    while (q--)
    {
        string op, set, s;

        cin >> op;

        if (op == "add")
        {
            cin >> set >> s;

            if (set == "A")
                A->insert(s, 0);
            else if (set == "B")
            {
                for (int i = 0; i < s.length() / 2; i++)
                    swap(s[i], s[s.length() - 1 - i]);

                B->insert(s, 0);
            }
        }
        else if (op == "delete")
        {
            cin >> set >> s;
            if (set == "A")
                A->erase(s, 0);
            else if (set == "B")
            {
                for (int i = 0; i < s.length() / 2; i++)
                    swap(s[i], s[s.length() - 1 - i]);
                B->erase(s, 0);
            }
        }
        else if (op == "find")
        {
            cin >> s;
            if (s.length() == 1)
            {
                cout << "0\n";
                continue;
            }
            int res = 0;

            vector<int> cnt_a(s.length()), cnt_b(s.length());

            A->search(s, 0, cnt_a);
            reverse(s.begin(), s.end());
            B->search(s, 0, cnt_b);

            for (int i = 0; i < s.length() - 1; i++)
            {

                res += cnt_a[i] * cnt_b[s.length() - 2 - i];
            }

            cout << res << "\n";
        }
    }
    return 0;
}