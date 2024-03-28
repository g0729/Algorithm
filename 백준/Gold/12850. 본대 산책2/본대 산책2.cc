#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define Matrix vector<vector<ll>>
Matrix multi(Matrix &a, Matrix &b)
{
    Matrix temp(8, vector<ll>(8));

    for (ll i = 0; i < 8; i++)
    {
        for (ll j = 0; j < 8; j++)
        {
            for (ll q = 0; q < 8; q++)
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
    Matrix temp(8, vector<ll>(8));

    if (cnt == 0)
    {
        for (int i = 0; i < 8; i++)
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

    ll d;
    cin>>d;
    Matrix a(8, vector<ll>(8));
    a={{0,1,1,0,0,0,0,0},{1,0,1,1,0,0,0,0},{1,1,0,1,1,0,0,0},
    {0,1,1,0,1,1,0,0},{0,0,1,1,0,1,0,1},{0,0,0,1,1,0,1,0},
    {0,0,0,0,0,1,0,1},{0,0,0,0,1,0,1,0}};

    Matrix res;
    res=mypow(a,d);
    cout<<res[0][0];
    return 0;
}