#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int num;
vector<int> tree;
vector<int> v;
int idx = 1;
void dfs(int node)
{
    if (node > num)
        return;

    dfs(node * 2);
    tree[node] = v[idx];
    idx++;
    dfs(node * 2 + 1);
}

void bfs()
{
    queue<int> q;
    q.push(1);

    int level = 1;
    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            int now = q.front();
            q.pop();
            cout << tree[now] << " ";

            if (now * 2 > num)
                continue;
            q.push(now * 2);
            q.push(now * 2 + 1);
        }
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    num = (1 << n) - 1;
    tree = vector<int>(num + 1);
    v = vector<int>(num + 1);

    for (int i = 1; i <= num; i++)
    {
        cin >> v[i];
    }

    dfs(1);
    bfs();

    return 0;
}