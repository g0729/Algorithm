#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

vector<int> v[50];
int n;
int root;
int k;
int res;

void dfs(int now)
{
    if (v[now].empty())
    {
        res++;
        return;
    }

    bool flag = false;
    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i];

        if (next == k)
            continue;

        dfs(next);
        flag = true;
    }
    if (!flag)
        res++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == -1)
        {
            root = i;
            continue;
        }
        v[a].push_back(i);
    }

    cin >> k;
    if (k == root)
    {
        cout << "0";
        return 0;
    }
    dfs(root);

    cout << res;
    return 0;
}