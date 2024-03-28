#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define Matrix vector<vector<ll>>

ll n, m;
Matrix multi(Matrix &a, Matrix &b)
{
    Matrix temp(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            for (ll q = 0; q < n; q++)
            {
                temp[i][j] += a[i][q] * b[q][j];
                temp[i][j] = temp[i][j] % MOD;
            }
        }
    }
    return temp;
}
Matrix mypow(Matrix &a, ll cnt)
{
    Matrix temp(n, vector<ll>(n));
    if (cnt == 0)
    {
        for (int i = 0; i < n; i++)
        {
            temp[i][i] = 1;
        }
        return temp;
    }
    if (cnt == 1)
        return a;
    temp = mypow(a, cnt / 2);
    temp = multi(temp, temp);
    if (cnt % 2 == 1)
        temp = multi(temp, a);

    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    Matrix MAP(n, vector<ll>(n));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a - 1][b - 1] = 1;
        MAP[b - 1][a - 1] = 1;
    }

    ll d;
    cin >> d;

    Matrix res;
    res = mypow(MAP, d);

    cout << res[0][0];
    return 0;
}