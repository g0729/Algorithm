#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int n;
vector<int> v;
vector<bool> weights;
int sel[13];
void dfs(int now)
{
    if (now == n)
    {
        int sum1, sum2;
        sum1 = sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (sel[i] == 1)
                sum1 += v[i];
            else if (sel[i] == 2)
                sum2 += v[i];
        }
        weights[abs(sum1 - sum2)] = true;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        sel[now] = i;
        dfs(now + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    v = vector<int>(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    weights = vector<bool>(sum + 1);
    dfs(0);
    int res = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (!weights[i])
            res++;
    }
    cout << res;
    return 0;
}