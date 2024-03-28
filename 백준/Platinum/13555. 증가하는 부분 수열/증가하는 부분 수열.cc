#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 5000000
#define MAX 100000

vector<vector<ll>> tree(51, vector<ll>((MAX + 1)));
vector<ll> v(MAX+1);


void update(int idx,int val,int num)
{
    while(idx<=MAX)
    {
        tree[num][idx]=(tree[num][idx]+val)%MOD;
        idx=idx+(idx&-idx);
    }
}
ll sum(int idx,int num)
{
    ll res=0;
    while(idx>0)
    {
        res=(res+tree[num][idx])%MOD;
        idx=idx-(idx&-idx);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        update(v[i],1,1);

        for (int j = 2; j <= k; j++)
        {
            ll temp = sum(v[i] - 1, j - 1);

            update(v[i], temp, j);
        }
    }

    cout << sum(MAX, k);

    return 0;
}