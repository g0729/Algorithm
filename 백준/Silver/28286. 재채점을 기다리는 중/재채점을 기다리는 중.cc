#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int n, k;
vector<int> v;
vector<int> answer;
int res = 0;

void dfs(int cnt, vector<int> now)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (now[i] == answer[i])
            temp++;
    }
    res = max(res, temp);

    if (cnt == k)
        return;

    for (int i = 0; i < n; i++)
    {
        vector<int> next(n);

        for (int j = 0; j < i; j++)
            next[j] = now[j];
        for (int j = i; j < n - 1; j++)
            next[j] = now[j + 1];
        dfs(cnt + 1, next);

        next[i] = 0;
        for (int j = i + 1; j < n; j++)
            next[j] = now[j - 1];
        dfs(cnt + 1, next);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        answer.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    dfs(0, v);

    cout << res;
    return 0;
}