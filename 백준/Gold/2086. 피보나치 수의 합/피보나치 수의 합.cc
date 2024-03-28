#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define matrix vector<vector<lint>>
#define MOD 1000000000
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
int main()
{
    lint a,b;
    cin>>a>>b;
    a= a+1;
    b =b+2;
    matrix res_a = {{1,0},{0,1}};
    matrix temp_a ={{1,1},{1,0}};
    while(a>0)
    {
        if(a%2==1)
        {
            res_a = res_a*temp_a;
        }
        temp_a = temp_a*temp_a;
        a /=2;
    }
    matrix res_b = {{1,0},{0,1}};
    matrix temp_b ={{1,1},{1,0}};
    while(b>0)
    {
        if(b%2==1)
        {
            res_b = res_b*temp_b;
        }
        temp_b = temp_b*temp_b;
        b /=2;
    }
    lint res= res_b[0][1]-res_a[0][1];
    while(res<0)
    {
        res+=MOD;
    }
    cout<<res%MOD;
}