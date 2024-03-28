#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define MAX 2001 
lint n,m,k;
lint arr[MAX][MAX];
int main()
{
    cin>>n>>m>>k;
    for (int i = 0; i < k; i++)
    {
        arr[i][0]=1;
        for (int q = 1; q <= i; q++)
        {
            arr[i][q]=(arr[i-1][q-1]+arr[i-1][q])%k;
        }
    }
    lint res=1;
    while(1)
    {
        if(n==0&&m==0)
        break;
        res=(res*arr[n%k][m%k])%k;
        n=n/k;
        m=m/k;
    }
    cout<<res;
}