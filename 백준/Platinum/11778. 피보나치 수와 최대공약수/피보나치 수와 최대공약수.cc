#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define matrix vector<vector<lint>>
#define MOD 1000000007
matrix operator *(const matrix &a ,const matrix &b)
{
    int k= a.size();
    matrix c(k,vector<lint>(k));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int q = 0; q < k; q++)
            {
                c[i][j]+=a[i][q]*b[q][j];
            }
            c[i][j]=c[i][j]%MOD;
        }
    }
    return c;
}
lint gcd(lint a,lint b)
{
    if(b==0)
    return a;
    else{
        return gcd(b,a%b);
    }
}
int main()
{
    lint n,m;
    cin>>n>>m;
    lint N=gcd(n,m);

    matrix res={{1,0},{0,1}};
    matrix temp={{1,1},{1,0}};
    while(N>0)
    {
        if(N%2==1)
        {
            res =res*temp;
        }
        temp = temp*temp;
        N=N/2;
    }
    
    cout<<res[0][1];
}

